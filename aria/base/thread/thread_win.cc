// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/thread.h"

#include <process.h>

namespace aria {

namespace {

unsigned int __stdcall ThreadFunc(void* params) {
  Thread* self = static_cast<Thread*>(params);
  self->Run();

  return 0;
}

}  // namespace

Thread::Thread()
    : thread_handle_(nullptr) {
}

Thread::~Thread() {
  CloseHandle(thread_handle_);
}

void Thread::Start() {
  thread_handle_ = reinterpret_cast<HANDLE>
      (_beginthreadex(nullptr, 0, ThreadFunc, this, 0, nullptr));
}

void Thread::Join() {
  WaitForSingleObject(thread_handle_, INFINITE);
}

}  // namespace aria
