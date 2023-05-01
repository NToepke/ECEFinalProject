#ifndef FURNITURE_H
#define FURNITURE_H
#include <string>
#include "InteractObject.h"
#include "Quest.h"

class Furniture : public InteractObject{
    public:
        std::string name;
        std::string description;
        Quest::Quest giveQuest();

};

#endif