#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int recJump (long unsigned int curP, vector<int> c, long unsigned int sum){
    if (curP == c.size()-1){
        return sum;
    }
    if (curP < c.size() && c.at(curP) != 1){
        return min( recJump(curP+1, c, sum+1)
                  , recJump(curP+2, c, sum+1));
    }
    return INT_MAX;
}

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) { 
    return recJump(0, c, 0);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
