#include "Furniture.h"

Furniture::Furniture()
{
    name = "Unnamed"; 
}

Furniture::Furniture(std::string name)
{
    this->name = name;
}

void Furniture::setDescriptions(std::vector<std::string> descriptions)
{
    this->descriptions = descriptions;
}

std::string Furniture::giveDescription(int currentProgression)
{
    return this->descriptions[currentProgression];
}