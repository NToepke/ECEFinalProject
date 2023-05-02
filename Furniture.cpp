#include "Furniture.h"

Furniture::Furniture()
{
    name = "Unnamed"; 
}

Furniture::Furniture(std::string name)
{
    this.name = name;
}

int Furniture::addContents(std::vector<Furntiture> appendContents)
{
    this.contents += appendContents;
}

std::string Furniture::giveDescription(int currentProgression)
{
    //CHECK if there is contents that need to be passed into the player
    //aka: a bookshelf has 3 books. you interact with the shelf. the player be able to
    //access the books in the menu after getting this description
    //Where are these stored? Maybe we need a map in here.
    //or we can move Contents to their own class, with a variable dictating when it should be available.



    return this.descriptions[currentProgression];
}