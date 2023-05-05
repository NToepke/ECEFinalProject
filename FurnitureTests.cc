#include <gtest/gtest.h>
#include "Furniture.h"
//I cannot for the life of me figure out how to add this to my VSCode
//So it will constantly be squiggly red line for me I guess.


// Demonstrate some basic assertions.
TEST(FurnitureConstructor, ThreeParams) {
  Furniture* tempA = new Furniture("tempA",{"The first Story","The second story!", "The THIRD story?"},{"NONE","NONE","NONE"});
  Furniture* tempB = new Furniture("tempB",{"B story One","B second story!", "The THIRD story?"},{"NONE","NONE","NONE"});
  EXPECT_NE(tempA->name,tempB->name);
  EXPECT_EQ(tempA->descriptions[2],tempB->descriptions[2]);
  EXPECT_EQ(tempA->increments[2],tempA->increments[2]);
}

TEST(FurnitureConstructor, TwoParams) {
  Furniture tempA = Furniture("tempA",{"The first Story","The second story!", "The THIRD story?"});
  Furniture tempB = Furniture("tempB",{"B story One","B second story!", "The THIRD story?"});
  EXPECT_NE(tempA.name,tempB.name);
  EXPECT_EQ(tempA.descriptions[2],tempB.descriptions[2]);
}

TEST(FurnitureConstructor, OneParam) {
  Furniture tempA = Furniture("tempA");
  Furniture tempB = Furniture("tempB");
  EXPECT_NE(tempA.name,tempB.name);
}

TEST(FurnitureConstructor, NoParam) {
  Furniture tempA = Furniture();
  Furniture tempB = Furniture();
  EXPECT_EQ(tempA.name,tempB.name);
}

TEST(FurnitureMethods, goodDescription) {
  Furniture tempA = Furniture("tempA",{"The first Story","The second story!", "The THIRD story?"},{"NONE","NONE","JEFF"});
  EXPECT_NE(tempA.name,"tempA");
  EXPECT_EQ(tempA.descriptions[2],"The THIRD story?");
  EXPECT_EQ(tempA.increments[2],"NONE");

  tempA.setDescriptions({"Yes","No","Maybe"});
  EXPECT_EQ(tempA.descriptions[0],"Yes");
  EXPECT_EQ(tempA.descriptions[1],"No");
  EXPECT_EQ(tempA.descriptions[2],"Maybe");

  EXPECT_EQ(tempA.giveDescription(0),"Yes");
  EXPECT_EQ(tempA.giveDescription(1),"No");
  EXPECT_EQ(tempA.giveDescription(2),"Maybe");
}