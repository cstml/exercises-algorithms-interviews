#include <sum.h>
#include <helloworld.h>
#include <iostream>
#include <cstdio>
#include <draw.h>

int main()
{
    Operations what;
    WindowSquare game;
    
    int a=10;
    int b=30;
    int d;
    d = what.sum(a,b);
    printf ("%i \n",d);

    d = what.sum(a,b,a);
    printf ("%i \n",d);

    HW();
}
