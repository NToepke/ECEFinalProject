#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
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

    std::cout << 1 <<". " << ((currentOptions)->at(0))->name << std::endl;
    std::cout << 2 <<". " << ((currentOptions)->at(1))->name << std::endl;
    std::cout << 3 <<". " << ((currentOptions)->at(2))->name << std::endl;


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
    std::fstream fs;
    std::fstream ofs;
    std::vector<InteractObject*> newStory;
    std::string locationToLoad = player->Location + ".txt";
    std::string temp;
    std::string tempDialogue;
    std::string tempType;
    int count = 1;
    std::vector<std::string> descriptionsToLoad;
    std::vector<std::string> objects;

    try {
        fs.open(locationToLoad, std::ios::out | std::ios::in | std::ios::binary);
        if (!fs.is_open()) {
            throw locationToLoad;
        }
    }
    catch(std::string ex) {
        std::cout<< "failed to load location " << ex << std::endl;
        return;
    }
    
    
    while(fs >> temp) {
        objects.push_back(temp);
    }
    fs.close();
    fs.clear();
    for (std::string object : objects) {
        try {
            std::string temp = object;
            temp.append(".txt");
            std::ifstream dataFile(temp.c_str());
            if (!dataFile.is_open()) {
                throw object;
            } else {
                count = 1;
            }
            while(std::getline(dataFile, tempDialogue)) {
            if (count % 7 == 0) {
                // Switching what location the player will go to next (Can change this to be on that specific option this is just a temp solution)
                player->Location = tempDialogue; 
            }
            if (count % 8 == 0) {
                tempType = tempDialogue;
            }
            if (count % 2 == 0 && count % 8 != 0) {
                // Object to increment in option goes here (This will hit lines 2 4 6)
            }
            if (count % 2 == 1 && count % 7 != 0) {
                descriptionsToLoad.push_back(tempDialogue);
            }
            count++;
        }
        newStory.push_back(factory.getInteractObject(tempType, object, descriptionsToLoad));
        descriptionsToLoad.clear();
        dataFile.close();
        std::cin.clear();
        } catch(std::string x) {
            std::cout << "Failed To load " << x << std::endl;
            return;
        }
    }
    player->addInteraction(newStory[0]);
    player->addInteraction(newStory[1]);
    player->addInteraction(newStory[2]);
}

int main()
{
    Player* player = Player::getInstance(); //Create the player
    player->Location = "Start";
    InteractObjectFactory factory;
    //Intro
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
    return EXIT_SUCCESS;
}