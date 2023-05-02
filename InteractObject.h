#ifndef INTERACT_H
#define INTERACT_H
#include <string>
#include <vector>

class InteractObject {
    public:
        std::string name;
        std::vector<std::string> descriptions;
        virtual std::string giveDescription(int currentProgression) = 0;
};

#endif