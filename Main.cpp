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

    if(currentOptions->size() == 0)
    {
        return "-1";
    }
    for(unsigned i = 1; i <= currentOptions->size(); i++)
    {
        //get the string from each InteractObject to print for user selection
        //print the name for user to see and choose from.
        std::cout << i <<". " << currentOptions->at(i-1)->name << std::endl;
    }
    //read userInput
    std::cin >> userInput;
    /*
    
    Error trap here for bad user input
    
    */
    //Get the return value
    int currentProgression = progressionMap->at(currentOptions->at(userInput-1)->name);
    std::string printDesc = currentOptions->at(userInput-1)->descriptions[currentProgression];
    
    
    //Increment the map, which tells the player not to reuse this line.
    int checkFail = player->incrementInteractionMap(currentOptions->at(userInput-1)->name);
    //check if the increment failed.
    if(checkFail == -1)
    {
        std::cerr << "Increment failed, look above for error from method." << std::endl;
        //game is broken, exit out
        return "-1";
    }

    //check if any interactions need to be removed from the list.
    player->validateInteractions();

    return printDesc;
}

void basicStory(Player* player, InteractObjectFactory factory)
{
    std::vector<InteractObject*> newStory;

    newStory.push_back(factory.getInteractObject("Furniture","Bookshelf",{"Its a bookshelf covered in books.","Story 2","Story 3"}));
    newStory.push_back(factory.getInteractObject("Npc","Jeff",{"Hi!","I read books. This one is about the bottom of a desk.","Story 3"}));
    newStory.push_back(factory.getInteractObject("Furniture","Desk",{"It's a small desk with no drawers.","There is a key stuck to the bottom of the desk.","Story 3"}));

    player->addInteraction(newStory[0]);
    player->addInteraction(newStory[1]);
    player->addInteraction(newStory[2]);
}

int main()
{
    Player* player = Player::getInstance(); //Create the player
    InteractObjectFactory factory;
   
    //Intro
    std::cout << "Welcome to the ECE Escape room. Surely you computer scientists will never get out.\n"
    <<"Only computer engineers with real world technical skills like soldering and suffering through\n"
    <<"More than just one logic gate class will be able to escape! Are you up to the task?\n\n"
    <<"You've been locked in this small room with only a few people and notable items.\n"
    <<"If you have your wits about you, you might be able to deduce your way out!\n\n\n"
    <<"You will be given a list of items in the room to interact with. Enter the number\n"
    <<"that corresponds to the item you'd like to investigate further. Good luck and have fun!" <<std::endl;

    //generate story
    basicStory(player,factory);
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
    std::cout << "\n\nGAME OVER\n\n\nThanks for playing!\n\n" << std::endl;
    return EXIT_SUCCESS;
}