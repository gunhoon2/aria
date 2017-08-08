// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/time/steady_clock.h"

#include <chrono>

namespace aria {

Time SteadyClock::Now() {
  // std::chrono::time_point<std::chrono::steady_clock>
  auto now = std::chrono::steady_clock::now();

  int64_t time_delta = std::chrono::duration_cast<std::chrono::nanoseconds>(
     now.time_since_epoch()).count();

  return Time(TimeDelta(time_delta));
}

}  // namespace aria
