// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_THREAD_LOCK_H_
#define ARIA_THREAD_LOCK_H_

#include "aria/thread/mutex.h"

namespace aria {

// The class AutoLock is a mutex wrapper that provides a convenient RAII-style
// mechanism for owning a mutex for the duration of a scoped block.
// This is similar to std::lock_guard class.
class AutoLock {
 public:
  explicit AutoLock(Mutex& m) : mutex_(m) {
    mutex_.Lock();
  }

  ~AutoLock() {
    mutex_.Unlock();
  }

 private:
  Mutex& mutex_;

  AutoLock(const AutoLock&) = delete;
  AutoLock& operator=(const AutoLock&) = delete;
};

}  // namespace aria

#endif  // ARIA_THREAD_LOCK_H_
