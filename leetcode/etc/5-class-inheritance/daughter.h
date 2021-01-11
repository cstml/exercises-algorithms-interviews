//daughter.h
//daughter class
//inherit stuff from

#ifndef DAUGHTER_H
#define DAUGHTER_H
#include "mother.h"
#include <string>

class Daughter:public Mother
{
    public:
        void SayHello();
        Daughter(std::string);
        Daughter();
    private:
        std::string name = "Daughter";
    protected:
};

#endif
