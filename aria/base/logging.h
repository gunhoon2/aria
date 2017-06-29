// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_LOGGING_H_
#define ARIA_BASE_LOGGING_H_

#include <sstream>

namespace aria {
namespace logging {

typedef int LogSeverity;
const LogSeverity LOG_INFO = 0;
const LogSeverity LOG_WARNING = 1;
const LogSeverity LOG_ERROR = 2;
const LogSeverity LOG_FATAL = 3;
const LogSeverity LOG_NUM_SEVERITIES = 4;


class LogMessage {
 public:
  LogMessage(const char* file, int line, LogSeverity severity);
  ~LogMessage();

  std::ostream& stream() { return stream_; }

 private:
  void Init();

  std::ostringstream stream_;
  LogSeverity severity_;

  const char* file_;
  const int line_;

  LogMessage(const LogMessage&) = delete;
  LogMessage& operator=(const LogMessage&) = delete;
};

// This class is used to explicitly ignore values in the conditional
// logging macros. This avoids compiler warnings like "value computed
// is not used" and "statement has no effect".
class LogMessageVoidify {
 public:
  LogMessageVoidify() { }
  // This has to be an operator with a precedence lower than << but
  // higher than ?:
  void operator&(std::ostream&) { }
};


// ---------------------- Logging Macro definitions --------------------------

#define _ARIA_LOG_INFO \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_INFO)
#define _ARIA_LOG_WARNING \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_WARNING)
#define _ARIA_LOG_ERROR \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_ERROR)
#define _ARIA_LOG_FATAL \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_FATAL)

#if defined(OS_WIN)
// wingdi.h defines ERROR to be 0. When we call LOG(ERROR), it gets
// substituted with 0, and it expands to _ARIA_LOG_0.
#define _ARIA_LOG_0 _ARIA_LOG_ERROR
#endif

// TODO(gunhoon): should implement
#define LOG_IS_ON(severity) (true)

// Macro which call the stream() member function of LogMessage
#define LOG_STREAM(severity) _ARIA_LOG_##severity.stream()

// Helper macro which avoids evaluating the arguments to a stream if
// the condition doesn't hold. Condition is evaluated once and only once.
#define LAZY_STREAM(stream, condition) \
  !(condition) ? (void) 0 : aria::logging::LogMessageVoidify() & (stream)

#define LOG(severity) LAZY_STREAM(LOG_STREAM(severity), LOG_IS_ON(severity))
#define LOG_IF(severity, condition) \
  LAZY_STREAM(LOG_STREAM(severity), LOG_IS_ON(severity) && (condition))

#define CHECK(condition) \
  LOG_IF(FATAL, !(condition)) << "Check failed: " #condition ". "
#define DCHECK(condition) \
  LOG_IF(FATAL, !(condition)) << "Check failed: " #condition ". "

#define LOG_ASSERT(condition) \
  LOG_IF(FATAL, !(condition)) << "Assert failed: " #condition ". "

}  // namespace logging
}  // namespace aria

#endif  // ARIA_BASE_LOGGING_H_
