//brother.cpp
//
//this is where I define what the brother class
//does
#include "brother.h"
#include <iostream>
#include <string>

Brother::Brother()
{}

Brother::Brother (std::string s)  
    :name(s)
{}

void Brother::SayHello ()
{
    std::cout<<"Hi my name is "<<name<<std::endl;
    return;
}
