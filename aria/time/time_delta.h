// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_TIME_TIME_DELTA_H_
#define ARIA_TIME_TIME_DELTA_H_

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

  int64_t Count() const { return delta_; }

  // static
  static TimeDelta Zero() {
    return TimeDelta(0);
  }
  static TimeDelta Min() {
    return TimeDelta(std::numeric_limits<int64_t>::min());
  }
  static TimeDelta Max() {
    return TimeDelta(std::numeric_limits<int64_t>::max());
  }

  // implements unary +/- operators
  TimeDelta operator+() const {
    return TimeDelta(delta_);
  }
  TimeDelta operator-() const {
    return TimeDelta(-delta_);
  }

  // implements ++, -- operators
  TimeDelta& operator++() {
    ++delta_;
    return *this;
  }
  TimeDelta& operator--() {
    --delta_;
    return *this;
  }
  TimeDelta operator++(int) {
    return TimeDelta(delta_++);
  }
  TimeDelta operator--(int) {
    return TimeDelta(delta_--);
  }

  // implements assignment operators
  TimeDelta& operator+=(const TimeDelta& other) {
    delta_ += other.Count();
    return *this;
  }
  TimeDelta& operator-=(const TimeDelta& other) {
    delta_ -= other.Count();
    return *this;
  }
  TimeDelta& operator*=(int64_t other) {
    delta_ *= other;
    return *this;
  }
  TimeDelta& operator/=(int64_t other) {
    delta_ /= other;
    return *this;
  }
  TimeDelta& operator%=(int64_t other) {
    delta_ %= other;
    return *this;
  }

  // implements comparison operators
  bool operator==(const TimeDelta& other) const {
    return delta_ == other.delta_;
  }
  bool operator!=(const TimeDelta& other) const {
    return delta_ != other.delta_;
  }
  bool operator<(const TimeDelta& other) const {
    return delta_ < other.delta_;
  }
  bool operator>(const TimeDelta& other) const {
    return delta_ > other.delta_;
  }
  bool operator<=(const TimeDelta& other) const {
    return delta_ <= other.delta_;
  }
  bool operator>=(const TimeDelta& other) const {
    return delta_ >= other.delta_;
  }

 private:
  // Delta in nanoseconds.
  int64_t delta_;
};

}  // namespace aria

#endif  // ARIA_TIME_TIME_DELTA_H_
