#include "Player.h"
#include "Npc.h"
#include "Furniture.h"

/*
*/

int main()
{
    Player* player = Player.getInstance(); //Create the player
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
    vector<interactObject>* currentOptions = player->getOptions();
    map<std::string,int>* progressionMap = player->getInteractionMap();
    //variable to hold user selection
    int userInput = -1;
    for(int i = 1; i <= currentOptions.size(); i++)
    {
        //get the string from each InteractObject to print for user selection
        //print the name for user to see.
        std::cout << i <<". "<< currentOptions[i-1]->name << std::endl;

    }
    std::cin >> userInput;

    int currentProgression = progressionMap[currentOptions[i-1]->name];
    std::string printDesc = currentOptions[i-1].descriptions[currentProgression][0];
    //Run story portion of current interaction

    int checkFail = player->incrementInteractionMap(currentOptions[userInput-1]->name);
    if(checkFail == -1)
    {
        std::cerr << "Increment failed, look above for error from method." << std::endl;
        //game is broken, exit out
        return "-1";
    }

}