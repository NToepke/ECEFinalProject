#include "InteractObject.h"

class InteractObjectFactory {
    public:
        static InteractObject* getInteractObject(enum objectType);
}