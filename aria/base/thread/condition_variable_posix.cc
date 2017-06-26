// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/condition_variable.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include "aria/base/thread/mutex.h"

namespace aria {

ConditionVariable::ConditionVariable() {
  pthread_cond_init(&cv_, nullptr);
}

ConditionVariable::~ConditionVariable() {
  pthread_cond_destroy(&cv_);
}

void ConditionVariable::NotifyOne() {
  pthread_cond_signal(&cv_);
}

void ConditionVariable::NotifyAll() {
  pthread_cond_broadcast(&cv_);
}

void ConditionVariable::Wait(Mutex* mutex) {
  pthread_cond_wait(&cv_, &mutex->mutex_);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
