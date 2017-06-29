// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/condition_variable.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include <time.h>
#if !defined(OS_LINUX)
#include <sys/time.h>
#endif

#include "aria/base/logging.h"
#include "aria/base/thread/mutex.h"

namespace aria {

ConditionVariable::ConditionVariable() {
  int rv = 0;

#if defined(OS_LINUX)
  pthread_condattr_t attr;

  rv = pthread_condattr_init(&attr);
  DCHECK(rv == 0);
  rv = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
  DCHECK(rv == 0);

  rv = pthread_cond_init(&cv_, &attr);
  DCHECK(rv == 0);

  rv = pthread_condattr_destroy(&attr);
  DCHECK(rv == 0);
#else
  rv = pthread_cond_init(&cv_, nullptr);
  DCHECK(rv == 0);
#endif  // defined(OS_LINUX)
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

bool ConditionVariable::TimedWait(Mutex* mutex, long timeout_ms) {
  struct timespec relative_time;
  relative_time.tv_sec = timeout_ms / 1000;
  relative_time.tv_nsec = (timeout_ms % 1000) * 1000000;

  struct timespec absolute_time;
#if defined(OS_LINUX)
  clock_gettime(CLOCK_MONOTONIC, &absolute_time);
#else
  struct timeval now;
  gettimeofday(&now, nullptr);
  absolute_time.tv_sec = now.tv_sec;
  absolute_time.tv_nsec = now.tv_usec * 1000;
#endif

  absolute_time.tv_sec += relative_time.tv_sec;
  absolute_time.tv_nsec += relative_time.tv_nsec;
  absolute_time.tv_sec += absolute_time.tv_nsec / 1000000000;
  absolute_time.tv_nsec %= 1000000000;

  int rv = pthread_cond_timedwait(&cv_, &mutex->mutex_, &absolute_time);
  DCHECK(rv == 0 || rv == ETIMEDOUT);

  return rv == 0;
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
