// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/thread/recursive_mutex.h"

#if defined(ARIA_THREAD_PLATFORM_WIN)

namespace aria {

RecursiveMutex::RecursiveMutex() {
  InitializeCriticalSection(&mutex_);
}

RecursiveMutex::~RecursiveMutex() {
  DeleteCriticalSection(&mutex_);
}

void RecursiveMutex::Lock() {
  EnterCriticalSection(&mutex_);
}

bool RecursiveMutex::TryLock() {
  return !!TryEnterCriticalSection(&mutex_);
}

void RecursiveMutex::Unlock() {
  LeaveCriticalSection(&mutex_);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_WIN)
