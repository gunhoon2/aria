// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_TIME_TIME_H_
#define ARIA_TIME_TIME_H_

#include "aria/time/time_delta.h"

namespace aria {

// The Time class is similar to std::chrono::time_point.
class Time {
 public:

  Time() : delta_(TimeDelta::Zero()) {}
  explicit Time(const TimeDelta& delta) : delta_(delta) {}

  Time(const Time&) = default;
  Time& operator=(const Time&) = default;

  // implements unary +/- operators
  Time operator+() const {
    return *this;
  }
  Time operator-() const {
    return Time(-delta_);
  }

  // implements ++, -- operators
  Time& operator++() {
    ++delta_;
    return *this;
  }
  Time& operator--() {
    --delta_;
    return *this;
  }
  Time operator++(int) {
    return Time(delta_++);
  }
  Time operator--(int) {
    return Time(delta_--);
  }

  // implements assignment operators
  Time& operator+=(const TimeDelta& other) {
    delta_ += other;
    return *this;
  }
  Time& operator-=(const TimeDelta& other) {
    delta_ -= other;
    return *this;
  }

 private:
  TimeDelta delta_;
};

}  // namespace aria

#endif  // ARIA_TIME_TIME_H_
