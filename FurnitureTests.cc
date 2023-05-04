#include <gtest/gtest.h>
#include "Furniture.h"
//I cannot for the life of me figure out how to add this to my VSCode
//So it will constantly be squiggly red line for me I guess.


// Demonstrate some basic assertions.
TEST(HelloTest2, BasicAssertions2) {
  // Expect two strings not to be equal.
  //Furniture temp = Furniture("Jim");
  EXPECT_EQ(5,5);

  //EXPECT_NE(temp.name,Furniture().name);
  //EXPECT_NE(temp.name,Furniture("Jeff").name);
  // Expect equality.
}
