// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/event.h"

#if !defined(ARIA_THREAD_PLATFORM_WIN)

#include "aria/base/logging.h"

namespace aria {

Event::Event(ResetPolicy reset_policy, InitialState initial_state)
    : manual_reset_(reset_policy == ResetPolicy::MANUAL)
    , signaled_(initial_state == InitialState::SIGNALED) {
}

Event::~Event() = default;

void Event::Signal() {
  AutoLock lock(mutex_);

  if (signaled_)
    return;
  signaled_ = true;
  cv_.NotifyAll();
}

void Event::Reset() {
  AutoLock lock(mutex_);
  signaled_ = false;
}

bool Event::IsSignaled() {
  AutoLock lock(mutex_);

  return signaled_;
}

void Event::Wait() {
  AutoLock lock(mutex_);

  while (!signaled_) {
    cv_.Wait(&mutex_);
  }
  if (!manual_reset_)
    signaled_ = false;
}

bool Event::TimedWait(int timeout_ms) {
  CHECK(timeout_ms >= 0);

  // TODO(gunhoon): should implement
  Wait();
  return true;
}

}  // namespace aria

#endif  // !defined(ARIA_THREAD_PLATFORM_WIN)
