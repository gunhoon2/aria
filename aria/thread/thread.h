// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_THREAD_THREAD_H_
#define ARIA_THREAD_THREAD_H_

#include "aria/thread/platform.h"

namespace aria {

class Thread {
 public:
  Thread();
  virtual ~Thread();

  void Start();
  void Join();

  virtual void Run() = 0;

 private:
#if defined(ARIA_THREAD_PLATFORM_POSIX)
  pthread_t thread_handle_;
#elif defined(ARIA_THREAD_PLATFORM_WIN)
  HANDLE thread_handle_;
#endif

  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;
};

}  // namespace aria

#endif  // ARIA_THREAD_THREAD_H_
