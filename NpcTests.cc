#include <gtest/gtest.h>
#include "Npc.h"
//I cannot for the life of me figure out how to add this to my VSCode
//So it will constantly be squiggly red line for me I guess.


// Demonstrate some basic assertions.
TEST(NpcConstructor, ThreeParams) {
  Npc* tempA = new Npc("tempA",{"The first Story","The second story!", "The THIRD story?"},{"NONE","NONE","NONE"});
  Npc* tempB = new Npc("tempB",{"B story One","B second story!", "The THIRD story?"},{"NONE","NONE","NONE"});
  EXPECT_NE(tempA->name,tempB->name);
  EXPECT_EQ(tempA->descriptions[2],tempB->descriptions[2]);
  EXPECT_EQ(tempA->increments[2],tempA->increments[2]);
}

TEST(NpcConstructor, TwoParams) {
  Npc tempA = Npc("tempA",{"The first Story","The second story!", "The THIRD story?"});
  Npc tempB = Npc("tempB",{"B story One","B second story!", "The THIRD story?"});
  EXPECT_NE(tempA.name,tempB.name);
  EXPECT_EQ(tempA.descriptions[2],tempB.descriptions[2]);
}

TEST(NpcConstructor, OneParam) {
  Npc tempA = Npc("tempA");
  Npc tempB = Npc("tempB");
  EXPECT_NE(tempA.name,tempB.name);
}

TEST(NpcConstructor, NoParam) {
  Npc tempA = Npc();
  Npc tempB = Npc();
  EXPECT_EQ(tempA.name,tempB.name);
}

TEST(NpcMethods, goodDescription) {
  Npc tempA = Npc("tempA",{"The first Story","The second story!", "The THIRD story?"},{"NONE","NONE","JEFF"});
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