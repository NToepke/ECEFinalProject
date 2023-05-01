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

static map<std::string interactName,int progressionKey>* Player::getMap()
{
    return progressionMap;
}