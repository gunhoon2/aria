// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/condition_variable.h"

#if defined(ARIA_THREAD_PLATFORM_WIN)

#include "aria/base/thread/mutex.h"

namespace aria {

ConditionVariable::ConditionVariable() {
  InitializeConditionVariable(&cv_);
}

ConditionVariable::~ConditionVariable() = default;

void ConditionVariable::NotifyOne() {
  WakeConditionVariable(&cv_);
}

void ConditionVariable::NotifyAll() {
  WakeAllConditionVariable(&cv_);
}

void ConditionVariable::Wait(Mutex* mutex) {
  SleepConditionVariableSRW(&cv_, &mutex->mutex_, INFINITE, 0);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_WIN)
