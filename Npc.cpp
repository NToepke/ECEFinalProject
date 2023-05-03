#include "Npc.h"

Npc::Npc()
{
    this->name = "Unnamed";
}
Npc::Npc(std::string name)
{
    this->name = name;
}
Npc::Npc(std::string name, std::vector<std::string> descriptions)
{
    this->name = name;
    this->descriptions = descriptions;
}

void Npc::setDescriptions(std::vector<std::string> descriptions)
{
    this->descriptions = descriptions;
}

Npc::Npc(std::string name, std::vector<std::string> descriptions, std::vector<std::string> increments)
{
    this->name = name;
    this->descriptions = descriptions;
    this->increments = increments;
}

std::string Npc::giveDescription(int currentProgression)
{
    return "";
}