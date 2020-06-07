//mother.cpp
//
//this is where I define what the mother class
//does
#include "mother.h"
#include <iostream>
#include <string>


void Mother::SayHello()
{
    string char name = "Mother";
    // prints hello to the console
    // and returns nothing
    std::cout<<"Hi I am a"<<name<<"class \n";
    return;
}

void Mother::SayGoodbye()
{
    std::cout<<"Goodbye!"<<std::endl;
}
