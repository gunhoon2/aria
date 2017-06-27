// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/recursive_mutex.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include "aria/base/logging.h"

namespace aria {

RecursiveMutex::RecursiveMutex() {
  pthread_mutexattr_t attr;

  int rv = pthread_mutexattr_init(&attr);
  DCHECK(rv == 0);
  rv = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  DCHECK(rv == 0);

  rv = pthread_mutex_init(&mutex_, &attr);
  DCHECK(rv == 0);

  rv = pthread_mutexattr_destroy(&attr);
  DCHECK(rv == 0);
}

RecursiveMutex::~RecursiveMutex() {
  int rv = pthread_mutex_destroy(&mutex_);
  DCHECK(rv == 0);
}

void RecursiveMutex::Lock() {
  int rv = pthread_mutex_lock(&mutex_);
  DCHECK(rv == 0);
}

bool RecursiveMutex::TryLock() {
  int rv = pthread_mutex_trylock(&mutex_);
  DCHECK(rv == 0 || rv == EBUSY);

  return rv == 0;
}

void RecursiveMutex::Unlock() {
  int rv = pthread_mutex_unlock(&mutex_);
  DCHECK(rv == 0);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
