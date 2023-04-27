#ifndef PLAYER_H
#define PLAYER_H
#include "Quest.h"


class Player {
    private:
        static Player* instance;
        Player(){};


    public:
        static Player* getInstance();
};


#endif