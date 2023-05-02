#include "InteractObjectFactory.h"
#include "Furniture.h"
#include "Npc.h"

InteractObject* InteractObjectFactory::getInteractObject(std::string objectType, std::string name, std::vector<std::string> descriptions)
{
    if(objectType.compare("Furniture")==0)
    {
        return new Furniture(name,descriptions);
    }
    else if(objectType.compare("Npc")==0)
    {
        return new Npc(name,descriptions);
    }
    else
    {
        //Error
        //std::cout << "ERROR" << std::endl;
        return nullptr;
    }
}