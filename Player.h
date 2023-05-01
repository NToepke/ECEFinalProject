#ifndef PLAYER_H
#define PLAYER_H
#include <map.h>
#include <vector.h>
#include <string.h>
#include "InteractObject.h"


class Player {
    private:
        static Player* instance;
        static std::map<std::string interactName,int progressionKey> progressionMap;
        static std::vector<InteractObject> currentInteractions;
        Player(){};


    public:
        static Player* getInstance();
        static vector<InteractObject>* getOptions();
        static vector<InteractObject>* getMap();
};


#endif