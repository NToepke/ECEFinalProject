#include <gtest/gtest.h>
//I cannot for the life of me figure out how to add this to my VSCode
//So it will constantly be squiggly red line for me I guess.


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "hello");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
