// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_THREAD_CONDITION_VARIABLE_H_
#define ARIA_BASE_THREAD_CONDITION_VARIABLE_H_

#include "aria/base/thread/platform.h"

namespace aria {

class Mutex;

class ConditionVariable {
 public:
  ConditionVariable();
  ~ConditionVariable();

  void NotifyOne();
  void NotifyAll();
  void Wait(Mutex* mutex);
  bool TimedWait(Mutex* mutex, long timeout_ms);

 private:
#if defined(ARIA_THREAD_PLATFORM_POSIX)
  pthread_cond_t cv_;
#elif defined(ARIA_THREAD_PLATFORM_WIN)
  CONDITION_VARIABLE cv_;
#endif

  ConditionVariable(const ConditionVariable&) = delete;
  ConditionVariable& operator=(const ConditionVariable&) = delete;
};

}  // namespace aria

#endif  // ARIA_BASE_THREAD_CONDITION_VARIABLE_H_
