// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/logging.h"

#include "gtest/gtest.h"

namespace aria {

TEST(LoggingTest, Logging) {
  LOG(INFO) << "Hello World!";
  LOG(WARNING) << "Warning message";
  LOG(ERROR) << "Error message";

  LOG_IF(INFO, true) << "LOG_IF message when condition is true.";
  LOG_IF(INFO, false) << "LOG_IF message when condition is false.";

  CHECK(true);
  // CHECK(false);
  DCHECK(true);
  // DCHECK(false);

  LOG_ASSERT(true);
  // LOG_ASSERT(false);
}

}  // namespace aria
