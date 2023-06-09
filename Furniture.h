#ifndef FURNITURE_H
#define FURNITURE_H
#include "InteractObject.h"

/*
    The main difference between NPC and Furniture is the NPC's will be
    present throughout the entire run of the game, while furniture will
    be added and removed per each "room".
    Codewise, Furniture can be containers, they can contain more Furniture objects
    to allow for things like a bookshelf with books, or a table with candles, allowing 
    some nested behaviour that isn't necessary on the NPC's.
*/


class Furniture : public InteractObject{
    public:
        Furniture();
        ~Furniture();
        Furniture(std::string name);
        Furniture(std::string name,std::vector<std::string> descriptions);
        Furniture(std::string name,std::vector<std::string> descriptions,std::vector<std::string> increments);
        
        void setDescriptions(std::vector<std::string> descriptions);
        std::string giveDescription(int currentProgression);
        void setIncrement(int currentIncrement, std::string newIncrement);
        std::string giveIncrement(int currentIncrement);
        


};

#endif