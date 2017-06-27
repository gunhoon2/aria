// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/mutex.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include "aria/base/logging.h"

namespace aria {

Mutex::Mutex() {
  int rv = pthread_mutex_init(&mutex_, nullptr);
  DCHECK(rv == 0);
}

Mutex::~Mutex() {
  int rv = pthread_mutex_destroy(&mutex_);
  DCHECK(rv == 0);
}

void Mutex::Lock() {
  int rv = pthread_mutex_lock(&mutex_);
  DCHECK(rv == 0);
}

bool Mutex::TryLock() {
  int rv = pthread_mutex_trylock(&mutex_);
  DCHECK(rv == 0 || rv == EBUSY);

  return rv == 0;
}

void Mutex::Unlock() {
  int rv = pthread_mutex_unlock(&mutex_);
  DCHECK(rv == 0);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
