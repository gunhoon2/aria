// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_THREAD_THREAD_H_
#define ARIA_BASE_THREAD_THREAD_H_

#include "aria/base/thread/platform.h"

namespace aria {

class Thread {
 public:
  Thread();
  virtual ~Thread();

  void Start();
  void Join();

  virtual void Run() = 0;

 private:
  ThreadHandle thread_handle_;

  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;
};

}  // namespace aria

#endif  // ARIA_BASE_THREAD_THREAD_H_
