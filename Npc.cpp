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
    std::vector<std::string> descriptionsWithName;
    for(auto description : descriptions) {
        descriptionsWithName.push_back(this->name + ": " + description);
    }
    this->descriptions = descriptionsWithName;
}

void Npc::setDescriptions(std::vector<std::string> descriptions)
{
    std::vector<std::string> descriptionsWithName;
    for(auto description : descriptions) {
        descriptionsWithName.push_back(name + ": " + description);
    }
    this->descriptions = descriptionsWithName;
}

Npc::Npc(std::string name, std::vector<std::string> descriptions, std::vector<std::string> increments)
{
    this->name = name;
    std::vector<std::string> descriptionsWithName;
    for(auto description : descriptions) {
        descriptionsWithName.push_back(name + ": " + description);
    }
    this->descriptions = descriptionsWithName;
    this->increments = increments;
}

std::string Npc::giveDescription(int currentProgression)
{
    return this->descriptions[currentProgression];
}

Npc::~Npc()
{
    this->name = "";
    this->descriptions.clear();
    this->increments.clear();
}