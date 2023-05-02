#include "Furniture.h"

Furniture::Furniture()
{
    name = "Unnamed"; 
}

Furniture::Furniture(std::string name)
{
    this->name = name;
}

std::string Furniture::giveDescription(int currentProgression)
{
    return this->descriptions[currentProgression];
}