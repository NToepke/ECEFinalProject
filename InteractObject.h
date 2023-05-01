#ifndef INTERACT_H
#define INTERACT_H
#include <string>
#include <vector>

class InteractObject {
    public:
        virtual std::string name;
        virtual std::vector<std::string> descriptions;
        virtual std::string giveDescription(int currentProgression);
};

#endif