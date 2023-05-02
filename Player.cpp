#include <stdexcept>
#include <iostream>
#include "Player.h"

Player* Player::instance = NULL;

Player* Player::getInstance(){
    if(!instance){
        instance = new Player();
    }
    return instance;
}

std::vector<InteractObject>* Player::getOptions()
{
    return &currentInteractions;
}

std::map<std::string,int>* Player::getInteractionMap()
{
    return &progressionMap;
}

int Player::incrementInteractionMap(std::string interactName)
{
    try {
        progressionMap.at(interactName)++;
    }
    catch (const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return progressionMap.at(interactName);
}