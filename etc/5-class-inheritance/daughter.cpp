//daughter.cpp
//
//this is where I define what the daughter class
//does
#include "daughter.h"
#include <iostream>
#include <string>


void Daughter::SayHello()
{
    string char name  = "Daughter";
    // prints hello to the console
    // and returns nothing
    std::cout<<"Hi I am a"<<name<<"class \n";
    return;
}
