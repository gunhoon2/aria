// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/logging.h"

#include <cstdlib>
#include <iostream>

namespace aria {
namespace logging {

LogMessage::LogMessage(const char* file, int line, LogSeverity severity)
    : severity_(severity), file_(file), line_(line) {
  Init();
}

LogMessage::~LogMessage() {
  stream_ << std::endl;
  std::cerr << stream_.str();

  if (severity_ == LOG_FATAL) {
    std::abort();
  }
}

void LogMessage::Init() {
  stream_ << "[" << "IWEF"[severity_] << " " << file_ << ":" << line_ << "] ";
}

}  // namespace logging
}  // namespace aria
