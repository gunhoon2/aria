// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/recursive_mutex.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

namespace aria {

RecursiveMutex::RecursiveMutex() {
  pthread_mutexattr_t attr;

  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&mutex_, &attr);
  pthread_mutexattr_destroy(&attr);
}

RecursiveMutex::~RecursiveMutex() {
  pthread_mutex_destroy(&mutex_);
}

void RecursiveMutex::Lock() {
  pthread_mutex_lock(&mutex_);
}

bool RecursiveMutex::TryLock() {
  return !pthread_mutex_trylock(&mutex_);
}

void RecursiveMutex::Unlock() {
  pthread_mutex_unlock(&mutex_);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
