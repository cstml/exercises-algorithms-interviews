#include <bits/stdc++.h>

#define ul unsigned long 
#define ull unsigned long long
#define ll long long

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    auto fn = [](string s){
        sort(s.begin(),s.end());
        return std::hash<string>{}(s);
        };
    
    auto fn2 = [](std::map<ll, ll>&h, ul &word){
        if(h.find(word) != h.end()){
            h[word] += 1;
            return true;
        } else {
            h.insert(std::pair<ll,ll>(word, 1));
            return true;
        }
    };
    
    auto perm = [](ll &num){
        return (num * (num - 1))/2;
    };
    
    std::map<ll, ll> h;
    for (auto i = 1 ; i< s.size() ; i++){
        for (auto j = 0 ; j+i <= s.size() ; j++){
            auto st = s.substr(j,i);
            // cout<<j<<" "<<j+i<<" "<<st<<" "<<fn(st)<<"\n";
            ul hashed = fn(st);
            fn2(h, hashed);
        }
    }
    
    ll total = 0;
    for(auto x : h){
        total += perm(x.second);
        // cout<<x.first<<" "<<x.second<<" "<<total<<"\n";
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
