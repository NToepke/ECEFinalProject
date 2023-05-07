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

    if (progressionMap->at("Finish") == 1) {
        //Player has beaten first room
        return "-1";
    }
    //variable to hold user selection
    int userInput = -1;
    //There is no options for the player to choose from
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
    //get the return value, which is the description to show based on the users choice.
    int currentProgression = progressionMap->at(interactedObject->name);
    std::string printDesc = interactedObject->giveDescription(currentProgression);
    
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
    int fileLength = 0;
    int count = 0;
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
            //temp holds the objects name, to load the objects.txt file.
            std::string temp = object;
            temp.append(".txt");
            //load the filename into the filestream
            std::ifstream dataFile(temp.c_str());
            //error trap to see if file can be opened.
            if (!dataFile.is_open()) {
                throw object;
            } else {
                //file is open. Set the counter to be line 0, as thats the first line in the file.
                count = 0;
            }
            //loop through the file, getting each line to build the InteractObject.
            while(std::getline(dataFile, tempDialogue)) {
                if (tempDialogue.at(tempDialogue.size()-1) == '\n' || tempDialogue.at(tempDialogue.size()-1) == '\r') {
                    tempDialogue.resize(tempDialogue.size() - 1);
                }
                // 7 is the second to last line, indicating the next room
                // 8 is the type of this object given the file.
            if(count == 0)
            {
                fileLength = std::stoi(tempDialogue);
            }


            if (count % (fileLength - 1) == 0) {
                // Switching what location the player will go to next (Can change this to be on that specific option this is just a temp solution)
                player->Location = tempDialogue; 
            }
            if (count % fileLength == 0) {
                tempType = tempDialogue;
            }
            //every even line is the name of the object to increment.
            //this means when the associated text is shown, what other InteractObject does this text
            //advance? For example, if a bookshelf text is "You should ask jeff about this", the 
            //increment would likely be "Jeff" to move jeff to a new text to print.
            if (count % 2 == 0 && count % 8 != 0) {
                increments.push_back(tempDialogue);
            }
            //every odd line is the text to display at this progression value.
            //At the begining, the description is usually basic, saying something like "This is a thing. it looks normal."
            //as the story progresses, this dialogue will change to reflect story progression.
            if (count % 2 == 1 && count % 7 != 0) {
                descriptionsToLoad.push_back(tempDialogue);
            }
            count++; //increment counter, which is tracking which line of the .txt we are on.
        }
        //send this parsed object to the factory for creation, and then add it to the return value.
        newStory.push_back(factory.getInteractObject(tempType, object, descriptionsToLoad, increments));
        //clean up memory allocations
        descriptionsToLoad.clear();
        increments.clear();
        dataFile.close();
        std::cin.clear();
        //this catch is for the failed file opening.
        } catch(std::string x) {
            std::cout << "Failed To load " << x << std::endl;
            return;
        }
    }
    //loop through the created InteractObjects and add them to the player vector for tracking.
    for(auto story : newStory) {
        player->addInteraction(story);
    }
    //add one more interaction, which allows the game to track the end condition of the game.
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
    <<"More than just one logic gate class will be able to escape! Are you up to the task?\\n"
    <<"You've been locked in this small room with only a few people and notable items.\n"
    <<"If you have your wits about you, you might be able to deduce your way out!\n"
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