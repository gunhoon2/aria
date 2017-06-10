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


// ---------------------- Logging Macro definitions --------------------------

#define _ARIA_LOG_INFO \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_INFO).stream()
#define _ARIA_LOG_WARNING \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_WARNING).stream()
#define _ARIA_LOG_ERROR \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_ERROR).stream()
#define _ARIA_LOG_FATAL \
  aria::logging::LogMessage(__FILE__, __LINE__, aria::logging::LOG_FATAL).stream()

#define LOG(severity) _ARIA_LOG_##severity

}  // namespace logging
}  // namespace aria

#endif  // ARIA_BASE_LOGGING_H_
