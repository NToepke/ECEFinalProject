#ifndef INTERACT_H
#define INTERACT_H
#include <string>
#include <vector>

class InteractObject {
    public:
        std::string name;
        std::vector<std::string> descriptions;
        std::vector<std::string> increments;
        virtual void setDescriptions(std::vector<std::string> descriptions) = 0;
        virtual std::string giveDescription(int currentProgression) = 0;
        virtual void setIncrement(int currentIncrement, std::string newIncrement) = 0;
        virtual std::string giveIncrement(int currentIncrement) = 0;
        virtual ~InteractObject() = 0;
};

#endif