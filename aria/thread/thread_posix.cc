// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/thread/thread.h"

#if defined(ARIA_THREAD_PLATFORM_POSIX)

#include "aria/base/logging.h"

namespace aria {

namespace {

void* ThreadFunc(void* params) {
  Thread* self = static_cast<Thread*>(params);
  self->Run();

  return nullptr;
}

}  // namespace

Thread::Thread() {
}

Thread::~Thread() {
}

void Thread::Start() {
  int rv = pthread_create(&thread_handle_, nullptr, ThreadFunc, this);
  DCHECK(rv == 0);
}

void Thread::Join() {
  int rv = pthread_join(thread_handle_, nullptr);
  DCHECK(rv == 0);
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_POSIX)
