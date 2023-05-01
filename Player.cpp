#include "Player.h"

Player* Player::instance = NULL;

Player* Player::getInstance(){
    if(!instance){
        instance = new Player();
    }
    return instance;
}

static Vector<Quest>* Player::getQuests()
{
    return quests;
}