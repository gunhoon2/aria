// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/thread.h"

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
  pthread_create(&thread_handle_, nullptr, ThreadFunc, this);
}

void Thread::Join() {
  pthread_join(thread_handle_, nullptr);
}

}  // namespace aria
