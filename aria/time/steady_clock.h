// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_TIME_STEADY_CLOCK_H_
#define ARIA_TIME_STEADY_CLOCK_H_

#include "aria/time/time.h"

namespace aria {

// The SteadyClock class is similar to std::chrono::steady_clock
class SteadyClock {
 public:
  static Time Now();
};

}  // namespace aria

#endif  // ARIA_TIME_STEADY_CLOCK_H_
