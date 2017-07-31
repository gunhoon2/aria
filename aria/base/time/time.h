// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_TIME_TIME_H_
#define ARIA_BASE_TIME_TIME_H_

#include "aria/base/time/time_delta.h"

namespace aria {

// The Time class is similar to std::chrono::time_point.
class Time {
 public:
  Time(const Time&) = default;
  Time& operator=(const Time&) = default;

 private:
  TimeDelta delta_;
};

}  // namespace aria

#endif  // ARIA_BASE_TIME_TIME_H_
