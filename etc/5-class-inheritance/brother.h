#include "daughter.h"
#include <string>

class Brother : public Daughter
{
public:
    void SayHello();
    Brother(std::string);
    Brother();
private:
    std::string name;

};
