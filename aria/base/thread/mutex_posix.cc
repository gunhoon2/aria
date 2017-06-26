// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/mutex.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

namespace aria {

Mutex::Mutex() {
  pthread_mutex_init(&mutex_, nullptr);
}

Mutex::~Mutex() {
  pthread_mutex_destroy(&mutex_);
}

void Mutex::Lock() {
  pthread_mutex_lock(&mutex_);
}

bool Mutex::TryLock() {
  return !pthread_mutex_trylock(&mutex_);
}

void Mutex::Unlock() {
  pthread_mutex_unlock(&mutex_);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
