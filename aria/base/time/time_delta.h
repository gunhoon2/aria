// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_TIME_TIME_DELTA_H_
#define ARIA_BASE_TIME_TIME_DELTA_H_

#include <stdint.h>

#include <limits>

namespace aria {

// The TimeDelta class is similar to std::chrono::duration,
// which represents a time interval.
class TimeDelta {
 public:
  constexpr TimeDelta() : delta_(0) {}
  constexpr explicit TimeDelta(int64_t delta_ns) : delta_(delta_ns) {}

  TimeDelta(const TimeDelta&) = default;
  TimeDelta& operator=(const TimeDelta&) = default;

  constexpr int64_t Count() const { return delta_; }

  static constexpr TimeDelta Zero() {
    return TimeDelta(0);
  }
  static constexpr TimeDelta Min() {
    return TimeDelta(std::numeric_limits<int64_t>::min());
  }
  static constexpr TimeDelta Max() {
    return TimeDelta(std::numeric_limits<int64_t>::max());
  }

  // implements unary + and unary -
  constexpr TimeDelta operator+() const {
    return TimeDelta(delta_);
  }
  constexpr TimeDelta operator-() const {
    return TimeDelta(-delta_);
  }

  // implements ++, -- operator
  TimeDelta& operator++() {
    ++delta_;
    return *this;
  }
  TimeDelta operator++(int) {
    return TimeDelta(delta_++);
  }
  TimeDelta& operator--() {
    --delta_;
    return *this;
  }
  TimeDelta operator--(int) {
    return TimeDelta(delta_--);
  }


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

  // Comparison operators.
  constexpr bool operator==(const TimeDelta& other) const {
    return delta_ == other.delta_;
  }
  constexpr bool operator!=(const TimeDelta& other) const {
    return delta_ != other.delta_;
  }
  constexpr bool operator<(const TimeDelta& other) const {
    return delta_ < other.delta_;
  }
  constexpr bool operator<=(const TimeDelta& other) const {
    return delta_ <= other.delta_;
  }
  constexpr bool operator>(const TimeDelta& other) const {
    return delta_ > other.delta_;
  }
  constexpr bool operator>=(const TimeDelta& other) const {
    return delta_ >= other.delta_;
  }

 private:
  // Delta in nanoseconds.
  int64_t delta_;
};

}  // namespace aria

#endif  // ARIA_BASE_TIME_TIME_DELTA_H_
