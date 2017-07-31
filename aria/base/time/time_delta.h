// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_TIME_TIME_DELTA_H_
#define ARIA_BASE_TIME_TIME_DELTA_H_

#include <stdint.h>

namespace aria {

// The TimeDelta class is similar to std::chrono::duration,
// which represents a time interval.
class TimeDelta {
 public:
  TimeDelta() : delta_(0) {}
  explicit TimeDelta(int64_t delta_ns) : delta_(delta_ns) {}

  TimeDelta(const TimeDelta&) = default;
  TimeDelta& operator=(const TimeDelta&) = default;

 private:
  // Delta in nanoseconds.
  int64_t delta_;
};

}  // namespace aria

#endif  // ARIA_BASE_TIME_TIME_DELTA_H_
