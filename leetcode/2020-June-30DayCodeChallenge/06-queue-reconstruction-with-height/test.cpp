#include <vector>
#include  <fstream>
#include <iostream>
using namespace std;
#include <deque>
#include <string>
#include <algorithm>
#include <source.cpp>

void readV(vector<vector <int>> &vec)
{
    //function reads the test and creates the vector
    ifstream inn("test.in");
    string tempStr;
    getline (inn,tempStr);
    //cout<<tempStr<<"\n";
    tempStr.erase(0,1);

    for (string::iterator t=tempStr.begin(); t!= tempStr.end(); t++ )
    {
        //cout<<*t<<endl;
        if ( *t == '[' )
        {
            //cout<<*t<<" is now";
            t++;
            //cout<<*t<<endl;
            int nr1= *t-'0';
            t+=2;
            int nr2= *t-'0';

            vector <int> temp;
            temp.push_back(nr1);
            temp.push_back(nr2);
            //cout<<nr1<<" "<<nr2;
            vec.push_back(temp);
        }
    }
    return;
}

void outputV(vector<vector <int>> &vec)
{
    //this simply output the vetor for me to see if it is correct
    cout<<"\n";
    int sZ = vec.size();
    cout<<sZ<<endl<<"[";
    for (vector<int> t1 : vec)
    {
        cout<<"[";
        int cont = 0;
        for (int t2 : t1)
        {
            cout<<t2;
            if (cont == 0)
                cout<<",";
            cont++;
        }
        sZ--;
        if (sZ)
            cout<<"],";
        else
            cout<<"]]";
    }
    return;
}

int main()
{
    cout<<"all is good";

    Solution test;
    vector<vector<int>> people;
    readV(people);
    test.reconstructQueue(people);
    outputV(people);
}
