#ifndef FACTORY_H
#define FACTORY_H
#include "InteractObject.h"

class InteractObjectFactory {
    public:
        static InteractObject* getInteractObject(enum objectType);
}
#endif