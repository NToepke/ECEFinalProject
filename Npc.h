#ifndef NPC_H
#define NPC_H
#include "InteractObject.h"

/*
    The main difference between NPC and Furniture is the NPC's will be
    present throughout the entire run of the game, while furniture will
    be added and removed per each "room".
    Codewise, NPC's are not containers, they have set dialogue and progression
    pieces, but do not contain more InteractObjects.
*/

class Npc : public InteractObject{
    public:
        Npc();
        Npc(std::string name);
        Npc(std::string name, std::vector<std::string> descriptions);
        Npc(std::string name, std::vector<std::string> descriptions, std::vector<std::string> increments);
        ~Npc();

        void setDescriptions(std::vector<std::string> descriptions);
        std::string giveDescription(int currentProgression);
        void setIncrement(int currentIncrement, std::string newIncrement);
        std::string giveIncrement(int currentIncrement);
};

#endif