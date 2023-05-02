#include <iostream>
#include "Player.h"
#include "Npc.h"
#include "Furniture.h"
#include "InteractObject.h"
#include "InteractObjectFactory.h"

std::string runMenu(Player* player)
{
    //pull player variables into local scope for easier code readability
    std::vector<InteractObject*>* currentOptions = player->getInteractions();
    std::map<std::string,int>* progressionMap = player->getInteractionMap();
    //variable to hold user selection
    int userInput = -1;
    //for(unsigned i = 1; i <= currentOptions->size(); i++)
    //{
        //std::cout << currentOptions->at(0)->name;
        //get the string from each InteractObject to print for user selection
        //print the name for user to see.
        //std::cout << i <<". " << currentOptions->at(i-1)->name << std::endl;
    //}

    std::cout << 1 <<". " << ((Furniture*)(currentOptions)->at(0))->name << std::endl;
    std::cout << 2 <<". " << ((Npc*)(currentOptions)->at(1))->name << std::endl;
    std::cout << 3 <<". " << ((Furniture*)(currentOptions)->at(2))->name << std::endl;


    std::cin >> userInput;

    int currentProgression = progressionMap->at(currentOptions->at(userInput-1)->name);
    std::string printDesc = currentOptions->at(userInput-1)->descriptions[currentProgression];
    //Run story portion of current interaction
    int checkFail = player->incrementInteractionMap(currentOptions->at(userInput-1)->name);
    if(checkFail == -1)
    {
        std::cerr << "Increment failed, look above for error from method." << std::endl;
        //game is broken, exit out
        return "-1";
    }
    return printDesc;
}

void basicStory(Player* player, InteractObjectFactory factory)
{
    std::vector<InteractObject*> newStory;

    newStory.push_back(factory.getInteractObject("Furniture","Bookshelf",{"Its a bookshelf covered in books.","Story 2","Story 3"}));
    newStory.push_back(factory.getInteractObject("Npc","Jeff",{"Hi!","Story 2","Story 3"}));
    newStory.push_back(factory.getInteractObject("Furniture","Desk",{"It's a small desk with no drawers.","Story 2","Story 3"}));

    player->addInteraction(newStory[0]);
    player->addInteraction(newStory[1]);
    player->addInteraction(newStory[2]);
}

int main()
{
    Player* player = Player::getInstance(); //Create the player
    InteractObjectFactory factory;
    //Intro
    basicStory(player,factory);

    std::cout << "Flag" << player->getInteractions()->at(0)->name;

    //RunMenu loop
    std::string chosenInteraction = "";
    do
    {
        std::cout << chosenInteraction <<std::endl;
        chosenInteraction = runMenu(player);
    }
    while(chosenInteraction.compare("-1") != 0);
    //exit menu loop when game tells you to.
    //Thanks for playing message
    return EXIT_SUCCESS;
}