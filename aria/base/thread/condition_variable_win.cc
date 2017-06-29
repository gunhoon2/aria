// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/condition_variable.h"

#if defined(ARIA_THREAD_PLATFORM_WIN)

#include "aria/base/logging.h"
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

void ConditionVariable::TimedWait(Mutex* mutex, long timeout_ms) {
  if (!SleepConditionVariableSRW(&cv_, &mutex->mutex_, timeout_ms, 0)) {
    DCHECK(static_cast<DWORD>(ERROR_TIMEOUT) == GetLastError());
  }
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_WIN)
