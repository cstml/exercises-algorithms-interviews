//daughter.cpp
//
//this is where I define what the daughter class
//does
#include "daughter.h"
#include <iostream>
#include <string>

Daughter::Daughter()
{}

Daughter::Daughter (std::string s)  
    :name(s)
{}

void Daughter::SayHello ()
{
    std::cout<<"Hi my name is "<<name<<std::endl;
    return;
}
