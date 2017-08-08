// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/time/system_clock.h"

#include <chrono>

namespace aria {

Time SystemClock::Now() {
  // std::chrono::time_point<std::chrono::system_clock>
  auto now = std::chrono::system_clock::now();

  int64_t time_delta = std::chrono::duration_cast<std::chrono::nanoseconds>(
     now.time_since_epoch()).count();

  return Time(TimeDelta(time_delta));
}

}  // namespace aria
