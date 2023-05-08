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

void Player::addInteraction(InteractObject* toAdd)
{
    currentInteractions.push_back(toAdd);
    mapInteraction(toAdd);
}

void Player::validateInteractions()
{
    std::vector<InteractObject*>::iterator it;
    int i = 0;
    for(it = currentInteractions.begin(); it != currentInteractions.end(); it++,i++)
    {
        if((int)currentInteractions[i]->descriptions.size() <= interactionMap.at(currentInteractions[i]->name))
        {
            currentInteractions.erase(it);
            it--;
            i--;
        }
    }
}

void Player::mapInteraction(InteractObject* toAdd)
{
    interactionMap.insert({toAdd->name,0});
}

std::vector<InteractObject*>* Player::getInteractions()
{
    return &currentInteractions;
}

std::map<std::string,int>* Player::getInteractionMap()
{
    return &interactionMap;
}

int Player::incrementInteractionMap(std::string interactName)
{
    try {
        if(interactName.compare("NextRoom") == 0)
        {
            for(auto x : interactionMap)
            {
                incrementInteractionMap(x.first);
            }
            return 0;
        }
        else{
        interactionMap.at(interactName)++;
        }
    }
    catch (const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "interactName: " << interactName << std::endl;
        std::cerr << "interactName[size-1]: " << ((int)interactName[interactName.size()-1]) << std::endl;
        std::cerr << "interactName length: " << interactName.length() << std::endl;
        return -1;
    }
    return interactionMap.at(interactName);
}

Player::~Player()
{
    interactionMap.clear();
    for( InteractObject* x : currentInteractions)
    {
        //std::cerr << x->name;
        delete x;
    }
    currentInteractions.clear();
}