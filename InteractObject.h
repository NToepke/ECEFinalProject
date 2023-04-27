#ifndef INTERACT_H
#define INTERACT_H
#include <string>

class InteractObject {
    public:
        virtual std::string name;
        virtual Quest giveQuest() = 0;
};

#endif