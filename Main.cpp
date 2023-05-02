#include <iostream>
#include "Player.h"
#include "Npc.h"
#include "Furniture.h"
#include "InteractObject.h"

/*
*/

int main()
{
    Player* player = Player::getInstance(); //Create the player
    //Intro
    //RunMenu loop
    std::string chosenInteraction = "";
    do
    {
        chosenInteraction = runMenu(player);
    }
    while(chosenInteraction.compare("-1") != 0);
    //exit menu loop when game tells you to.
    //Thanks for playing message
    return EXIT_SUCCESS;
}

std::string runMenu(Player* player)
{
    //pull player variables into local scope for easier code readability
    std::vector<InteractObject>* currentOptions = player->getOptions();
    std::map<std::string,int>* progressionMap = player->getInteractionMap();
    //variable to hold user selection
    int userInput = -1;
    for(int i = 1; i <= currentOptions->size(); i++)
    {
        //get the string from each InteractObject to print for user selection
        //print the name for user to see.
        std::cout << i <<". " << currentOptions->at(i-1).name << std::endl;
    }
    std::cin >> userInput;

    int currentProgression = progressionMap->at(currentOptions->at(userInput-1).name);
    std::string printDesc = currentOptions->at(userInput-1).descriptions[currentProgression];
    //descriptions[currentProgression];
    //Run story portion of current interaction

    int checkFail = player->incrementInteractionMap();
    if(checkFail == -1)
    {
        std::cerr << "Increment failed, look above for error from method." << std::endl;
        //game is broken, exit out
        return "-1";
    }
    return "";
}