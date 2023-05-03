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
    if (player->isFinished()) {
        return "-1";
    }

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
    InteractObject* interactedObject = currentOptions->at(userInput-1);

    int currentProgression = progressionMap->at(interactedObject->name);
    std::string printDesc = interactedObject->descriptions[currentProgression];
    
    
    //Increment the map, which tells the player not to reuse this line.
    std::string interactionToIncrement = interactedObject->increments[currentProgression];
    if (interactionToIncrement.compare("NONE") != 0) {
        int checkFail = player->incrementInteractionMap(interactionToIncrement);
        if(checkFail == -1)
        {
            std::cerr << "Increment failed, look above for error from method." << std::endl;
            //game is broken, exit out
            return "-1";
        }
        interactedObject->increments[currentProgression] = "NONE";
    }
    //check if the increment failed.
    

    //check if any interactions need to be removed from the list.
    player->validateInteractions();

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
    std::vector<std::string> increments;


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
                increments.push_back(tempDialogue);
            }
            if (count % 2 == 1 && count % 7 != 0) {
                descriptionsToLoad.push_back(tempDialogue);
            }
            count++;
        }
        newStory.push_back(factory.getInteractObject(tempType, object, descriptionsToLoad, increments));
        descriptionsToLoad.clear();
        increments.clear();
        dataFile.close();
        std::cin.clear();
        } catch(std::string x) {
            std::cout << "Failed To load " << x << std::endl;
            return;
        }
    }
    for(auto story : newStory) {
        player->addInteraction(story);
    }

    player->mapInteraction(new Npc("Finish"));
}

int main()
{
    Player* player = Player::getInstance(); //Create the player
    player->Location = "Start";
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