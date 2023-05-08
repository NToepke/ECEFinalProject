#include "InteractObjectFactory.h"
#include "Furniture.h"
#include "Npc.h"

InteractObject* InteractObjectFactory::getInteractObject(std::string objectType, std::string name, std::vector<std::string> descriptions, std::vector<std::string> increments)
{
    if(objectType.compare("Furniture")==0)
    {
        Furniture* retVal = new Furniture(name,descriptions, increments);
        return retVal;
    }
    else if(objectType.compare("Npc")==0)
    {
        Npc* retVal = new Npc(name,descriptions, increments);
        return retVal;
    }
    else
    {
        //Error
        //std::cout << "ERROR" << std::endl
        return nullptr;
    }
}