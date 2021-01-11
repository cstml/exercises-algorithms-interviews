#include <iostream>

using namespace std;

int sumA(int a, int c)
{
    return a+c;
}

int main()
{
    int a=2;
    int b;
    int c=3;

    cin>>b;

    cout<<(a+b);
    cout<<endl;
    return sumA(a,c);

}
