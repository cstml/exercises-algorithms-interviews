#include <vector>
#include <string>
#include <cstring>
//#include <iostream>
#include <stdio.h>
using namespace std;

#define maxstring 100

int main ()
{
    
    char c[maxstring];
    char b[maxstring];
    char *d;


    fgets(b,100,stdin); // max lenght and where from
    fgets(c,100,stdin); // max lenght and where from

    if (strlen(b)!=0)
        if(b[strlen(b)-1]=='\n')
            b[strlen(b)-1] = '\0';

    if (strlen(c)!=0)
        if(c[strlen(c)-1]=='\n')
            c[strlen(c)-1] = '\0';
    printf ("You just wrote %s didn't you? \n",b);
    printf ("Length of %s is %li \n",b,strlen(b));

    d=strstr(b,c);
    printf ("%s \n",c);

    printf ("%s \n",d);
    return 0;
}
