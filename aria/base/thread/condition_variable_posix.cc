// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/condition_variable.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include "aria/base/logging.h"
#include "aria/base/thread/mutex.h"

namespace aria {

ConditionVariable::ConditionVariable() {
  int rv = pthread_cond_init(&cv_, nullptr);
  DCHECK(rv == 0);
}

ConditionVariable::~ConditionVariable() {
  int rv = pthread_cond_destroy(&cv_);
  DCHECK(rv == 0);
}

void ConditionVariable::NotifyOne() {
  int rv = pthread_cond_signal(&cv_);
  DCHECK(rv == 0);
}

void ConditionVariable::NotifyAll() {
  int rv = pthread_cond_broadcast(&cv_);
  DCHECK(rv == 0);
}

void ConditionVariable::Wait(Mutex* mutex) {
  int rv = pthread_cond_wait(&cv_, &mutex->mutex_);
  DCHECK(rv == 0);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
