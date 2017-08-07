// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/thread/mutex.h"

#if defined(ARIA_THREAD_PLATFORM_WIN)

namespace aria {

Mutex::Mutex() {
  InitializeSRWLock(&mutex_);
}

Mutex::~Mutex() = default;

void Mutex::Lock() {
  AcquireSRWLockExclusive(&mutex_);
}

bool Mutex::TryLock() {
  return !!TryAcquireSRWLockExclusive(&mutex_);
}

void Mutex::Unlock() {
  ReleaseSRWLockExclusive(&mutex_);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_WIN)
