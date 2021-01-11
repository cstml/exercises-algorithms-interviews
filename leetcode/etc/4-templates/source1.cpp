#include<iostream>
using namespace std;

template<typename T>
void Printer (T var,int a)
{
    for (int i = 0; i<a;i++)
        cout<<var<<"\n";
    return ;
}

int main()
{
    //a fantastic exmaple of how powerful templates can be
    //they allow you to instantiate a function
    //whenever it is called
    //based upon a pre-defined template
    //Very good when a polimorphysm would take a while to write

    Printer("Hello World",3);
    Printer(3,3);
    Printer (true, 4);
    return 0;
}
