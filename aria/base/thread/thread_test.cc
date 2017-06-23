// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/base/thread/thread.h"

#include "gtest/gtest.h"

namespace aria {

namespace {

bool constructed = false;
bool destructed = false;
bool started = false;

}  // namespace

class MyThread : public Thread {
 public:
  MyThread() { constructed = true; }
  ~MyThread() { destructed = true; }

  void Run() override {
    started = true;
  }
};

class ThreadTest : public testing::Test {
 public:
  ThreadTest() {
    constructed = false;
    destructed = false;
    started = false;
  }
};

TEST_F(ThreadTest, CtorAndDtor1) {
  Thread* ptr = new MyThread;
  EXPECT_TRUE(constructed);
  EXPECT_FALSE(destructed);

  delete ptr;
  EXPECT_TRUE(constructed);
  EXPECT_TRUE(destructed);
}

TEST_F(ThreadTest, CtorAndDtor2) {
  MyThread* ptr = new MyThread;
  EXPECT_TRUE(constructed);
  EXPECT_FALSE(destructed);

  delete ptr;
  EXPECT_TRUE(constructed);
  EXPECT_TRUE(destructed);
}

TEST_F(ThreadTest, StartAndJoin) {
  Thread* ptr = new MyThread;
  EXPECT_TRUE(constructed);
  EXPECT_FALSE(destructed);
  EXPECT_FALSE(started);

  ptr->Start();
  ptr->Join();
  EXPECT_TRUE(constructed);
  EXPECT_FALSE(destructed);
  EXPECT_TRUE(started);

  delete ptr;
  EXPECT_TRUE(constructed);
  EXPECT_TRUE(destructed);
  EXPECT_TRUE(started);
}

}  // namespace aria
