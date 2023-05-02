#include "Furniture.h"

Furniture::Furniture()
{
    name = "Unnamed"; 
}

Furniture::Furniture(std::string name)
{
    this->name = name;
}

Furniture::Furniture(std::string name, std::vector<std::string> descriptions)
{
    this->name = name;
    this->descriptions = descriptions;
}

void Furniture::setDescriptions(std::vector<std::string> descriptions)
{
    this->descriptions = descriptions;
}

std::string Furniture::giveDescription(int currentProgression)
{
    return this->descriptions[currentProgression];
}