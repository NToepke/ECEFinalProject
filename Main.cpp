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
    int result = runMenu();
    return EXIT_SUCCESS;
}

int runMenu(Player* player)
{
    vector<interactObject>* currentOptions = player->getOptions();
    map<std::string,int>* progressionMap = player->getMap();
    for(int i = 1; i <= currentOptions.size(); i++)
    {
        int currentProgression = progressionMap[currentOptions[i-1]->name];
        std::string printDesc = currentOptions[i-1].descriptions[currentProgression];

        std::cout << i <<". "<< printDesc << std::endl;
    }
}