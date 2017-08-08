// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_TIME_SYSTEM_CLOCK_H_
#define ARIA_TIME_SYSTEM_CLOCK_H_

#include "aria/time/time.h"

namespace aria {

// The SystemClock class is similar to std::chrono::system_clock
class SystemClock {
 public:
  static Time Now();
};

}  // namespace aria

#endif  // ARIA_TIME_SYSTEM_CLOCK_H_