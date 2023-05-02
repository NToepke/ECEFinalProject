#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <vector>
#include <string>
#include "InteractObject.h"


class Player {
    private:
        static Player* instance;
        /*
        This Map has a key of a string, which is the InteractObject string, and an Int value,
        The int value is used to track progression through the object on the player side.
        */
        static std::map<std::string,int> progressionMap; 
        static std::vector<InteractObject> currentInteractions;
        Player(){};


    public:
        static Player* getInstance();
        static std::vector<InteractObject>* getOptions();
        static std::map<std::string,int>* getInteractionMap();
        static int incrementInteractionMap(std::string interactName);
};


#endif