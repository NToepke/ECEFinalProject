#include "InteractObjectFactory.h"
#include "Furniture.h"
#include "Npc.h"

InteractObject* InteractObjectFactory::getInteractObject(std::string objectType, std::string name)
{
    if(objectType.compare("Furniture")==0)
    {
        return new Furniture(name);
    }
    else if(objectType.compare("Npc")==0)
    {
        return new Npc(name);
    }
    else
    {
        //Error
        //std::cout << "ERROR" << std::endl;
        return nullptr;
    }
}