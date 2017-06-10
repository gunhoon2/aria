// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/logging.h"

#include "gtest/gtest.h"

namespace aria {

TEST(LoggingTest, Logging) {
  LOG(INFO) << "Hello World!";
  LOG(WARNING) << "Warning message";
  LOG(ERROR) << "Error message";
}

}  // namespace aria
