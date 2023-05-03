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
        std::map<std::string,int> interactionMap; 
        std::vector<InteractObject*> currentInteractions;
        Player(){};

    public:
        static Player* getInstance();
        void addInteraction(InteractObject* toAdd);
        void mapInteraction(InteractObject* toAdd);
        std::vector<InteractObject*>* getInteractions();
        std::map<std::string,int>* getInteractionMap();
        std::string Location;
        int incrementInteractionMap(std::string interactName);
};


#endif