#include "Player.h"

Player* Player::instance = NULL;

Player* Player::getInstance(){
    if(!instance){
        instance = new Player();
    }
    return instance;
}

static vector<InteractObject>* Player::getOptions()
{
    return currentInteractions;
}

static map<std::string,int>* Player::getMap()
{
    return progressionMap;
}