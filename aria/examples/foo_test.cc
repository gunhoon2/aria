// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/examples/foo.h"

#include "gtest/gtest.h"

namespace aria {

class FooTest : public testing::Test {
};

TEST_F(FooTest, Example) {
  EXPECT_TRUE(true);
}

}  // namespace aria
