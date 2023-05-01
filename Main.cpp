#include <Vector.h>
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

    for(int i = 1; i < player->getOptions().size; i++)
    {
        std::cout << i <<". "<<player << std::endl;
    }
}