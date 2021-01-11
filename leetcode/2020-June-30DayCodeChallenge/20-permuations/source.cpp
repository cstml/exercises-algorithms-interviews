#include<iostream>
#include<vector>
#define ll long long
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<std::size_t> q;
        std::string slt;
        ll x=1;
        for(auto a =1;a<= n;a++)
            q.push_back(a);

        for (int i =1;i<n;i++)
            x*=i;

        n--;
        k--;
        while(n>=1)
        {
            int pos = k/x;
            slt+=std::to_string(q[pos]);
            q.erase(q.begin()+pos);
            k%=x;
            x/=n;
            n--;
        }
        slt+=std::to_string(q.front());
        return slt; 
    }
};

int main()
{
    Solution s;
    std::cout<<s.getPermutation(3,2)<<std::endl;

}
