// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_THREAD_MUTEX_H_
#define ARIA_BASE_THREAD_MUTEX_H_

#include "aria/base/thread/platform.h"

namespace aria {

class Mutex {
 public:
  Mutex();
  ~Mutex();

  void Lock();
  bool TryLock();
  void Unlock();

 private:
#if defined(ARIA_THREAD_PLATFORM_POSIX)
  pthread_mutex_t mutex_;
#elif defined(ARIA_THREAD_PLATFORM_WIN)
  SRWLOCK mutex_;
#endif

  Mutex(const Mutex&) = delete;
  Mutex& operator=(const Mutex&) = delete;
};

}  // namespace aria

#endif  // ARIA_BASE_THREAD_MUTEX_H_
