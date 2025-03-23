#include <gtest/gtest.h>
#include "../src/include/delegate.h"

TEST(dummyTest, nullptrEquality) {
  ES::Delegate* del = nullptr;
  EXPECT_EQ(del, nullptr);
}