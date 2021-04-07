/*
Secret here is to count it twice and divide, 

No Need to replicate the string. 

*/
#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    unsigned long long int rem   = n % s.size();
    unsigned long long int times = n / s.size();
    unsigned long long int count = 0;
    int interm = 0;
    for (unsigned long int i = 0 ; i < rem ; i++){
        if (s[i] == 'a'){
            count ++; 
        }
    }
    if (times != 0)
    {
        for (unsigned long int i = 0 ; i < s.size() ; i++){
            if (s[i] == 'a')
                interm ++; 
        }   
    }
    count += interm * times;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
