#include "Npc.h"

Npc::Npc()
{
    this->name = "Unnamed";
}
Npc::Npc(std::string name)
{
    this->name = name;
}

void Npc::setDescriptions(std::vector<std::string> descriptions)
{
    this->descriptions = descriptions;
}

std::string Npc::giveDescription(int currentProgression)
{
    return "";
}