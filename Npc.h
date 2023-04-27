#ifndef NPC_H
#define NPC_H
#include <string>
#include "InteractObject.h"
#include "Quest.h"

class Npc : public InteractObject{
    public:
        std::string name;
        Quest::Quest giveQuest();

};

#endif