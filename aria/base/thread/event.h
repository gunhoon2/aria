// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_THREAD_EVENT_H_
#define ARIA_BASE_THREAD_EVENT_H_

#include "aria/base/thread/platform.h"

#if !defined(ARIA_THREAD_PLATFORM_WIN)
#include "aria/base/thread/condition_variable.h"
#include "aria/base/thread/lock.h"
#endif  // !defined(ARIA_THREAD_PLATFORM_WIN)

namespace aria {

// The Event class is the cross-platform implementation of
// CreateEvent/WaitForSingleObject on Windows
class Event {
 public:
  enum class ResetPolicy { MANUAL, AUTOMATIC };
  enum class InitialState { NONSIGNALED, SIGNALED };

  Event(ResetPolicy reset_policy, InitialState initial_state);
  ~Event();

  void Signal();
  void Reset();
  bool IsSignaled();

  void Wait();
  // return true if no_timeout, else false.
  bool TimedWait(int timeout_ms);

 private:
#if defined(ARIA_THREAD_PLATFORM_WIN)
  HANDLE handle_;
#else
  Mutex mutex_;
  ConditionVariable cv_;

  const bool manual_reset_;
  bool signaled_;
#endif

  Event(const Event&) = delete;
  Event& operator=(const Event&) = delete;
};

}  // namespace aria

#endif  // ARIA_BASE_THREAD_EVENT_H_
