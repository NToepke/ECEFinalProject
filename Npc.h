#ifndef NPC_H
#define NPC_H
#include <string>
#include "InteractObject.h"
#include "Quest.h"

class Npc : public InteractObject{
    public:
        std::string name;
        std::string description;
        Quest::Quest giveQuest();

};

#endif