#ifndef PLAYER_H
#define PLAYER_H
#include "Quest.h"


class Player {
    private:
        static Player* instance;
        static Vector<Quest>* quests;
        Player(){};


    public:
        static Player* getInstance();
        static Vector<Quest>* getQuests();
};


#endif