#include <cstdio>
#include "d.h"
#include <iostream>

int Summation (int a, int b)
{
    return a+b;
}
int WriteItOut (void)
{
    printer ("This is a nice way to just write a string\n");
    printer (47);
    printf("File b \n");
    return 0;
}

int printer (std::string a)
{
    std::cout<<a;
    return 0;
}

int printer (int a)
{
    std::cout<<"I see you are a person of refined taste and you like polymorphism "<<a<<" I respect that \n";
    return 0;
}
