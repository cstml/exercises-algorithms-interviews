#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//template <typename T, typename T_V>
void Printer (vector <int> vec)
{
    for (int it : vec)
    {
        cout<<it<<" ";
    } 
    cout<<endl;
    return ;
}

void Printer (vector <float> vec)
{
    for (float it : vec)
    {
        cout<<it<<" ";
    } 
    cout<<endl;
    return ;
}

void Printer (vector <string> vec)
{
    for (string it : vec)
    {
        cout<<it<<" ";
    } 
    cout<<endl;
    return ;
}

void Indexify ( vector <int> from, vector<float>&to)
{
    //include the index into the number 
    //as a decimal
    long i=0;
    for(i;i < from.size();i++)
    {
        to.push_back(float(from[i]+float(i)/10));
    }
    return;
}

template <class T>
void CopyVec (vector<T> from, vector <T> &to){
    // copy a vector into another vector
    //
    for (int i=0;i<from.size();i++)
        to.push_back(from[i]);
    return ;
}

int main()
{
    // the idea of this script is to zip
    // the index of the name vector
    // with the number information
    // in a retreievable and non damaging mannner
    //
    //author: cstml
    //website: cstml.github.com
    //
    int myInts[]={1,532,452,60,30};
    string myStrings[]={"abra","ca","Da","bra","ma"};
    vector <int> vec(myInts,myInts+5);
    vector <int> vec3;
    vector <string> vec2(myStrings,myStrings+5);
    Printer(vec);
    CopyVec(vec,vec3);
    Printer(vec3);
    vector <float> vec4;
    Indexify(vec,vec4);
    sort(vec4.begin(),vec4.end());
    Printer(vec2);
    Printer(vec4);
    sort(vec2.begin(),vec2.end());
    return 0;

}

