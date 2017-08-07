// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/thread/event.h"

#if defined(ARIA_THREAD_PLATFORM_WIN)

#include "aria/base/logging.h"

namespace aria {

Event::Event(ResetPolicy reset_policy, InitialState initial_state)
    : handle_(CreateEvent(nullptr,
                          reset_policy == ResetPolicy::MANUAL,
                          initial_state == InitialState::SIGNALED,
                          nullptr)) {
  CHECK(handle_);
}

Event::~Event() {
  if (!CloseHandle(handle_)) {
    LOG(ERROR) << "The CloseHandle fails : " << GetLastError();
  }
}

void Event::Signal() {
  if (!SetEvent(handle_)) {
    LOG(ERROR) << "The SetEvent fails : " << GetLastError();
  }
}

void Event::Reset() {
  if (!ResetEvent(handle_)) {
    LOG(ERROR) << "The ResetEvent fails : " << GetLastError();
  }
}

bool Event::IsSignaled() {
  DWORD rv = WaitForSingleObject(handle_, 0);
  DCHECK(rv == WAIT_OBJECT_0 || rv == WAIT_TIMEOUT);

  return rv == WAIT_OBJECT_0;
}

void Event::Wait() {
  DWORD rv = WaitForSingleObject(handle_, INFINITE);
  DCHECK(rv == WAIT_OBJECT_0);
}

bool Event::TimedWait(int timeout_ms) {
  CHECK(timeout_ms >= 0);

  DWORD rv = WaitForSingleObject(handle_, timeout_ms);
  DCHECK(rv == WAIT_OBJECT_0 || rv == WAIT_TIMEOUT);

  return rv == WAIT_OBJECT_0;
}

}  // namespace aria

#endif  // defined(ARIA_THREAD_PLATFORM_WIN)
