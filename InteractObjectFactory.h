#ifndef FACTORY_H
#define FACTORY_H
#include "InteractObject.h"

class InteractObjectFactory {
    public:
        static InteractObject* getInteractObject(std::string objectType, std::string name, std::vector<std::string> descriptions);
};
#endif
