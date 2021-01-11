#include <iostream>
#include <string>
#include <vector>

using namespace std;

# define MAX_LEN 256

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) {
        
        vector <int> vec (MAX_LEN,-1);
        
        int subsL = 0;
        int maxL = 0;
        
        for (unsigned int i= 0 ; i < s.size() ; i++)
        {
            //cout<< s.at(i)<<endl;
            subsL ++;
            int posLet = vec[(s.at(i)-'a')%MAX_LEN];
            if (vec[posLet] == -1 )
                    vec[posLet] = i;
            else
            {
                int t = i - vec[posLet];
                if (t < subsL)
                    subsL = t;
                vec[posLet] = i;
            }
            
            if (subsL>maxL)
            {
                maxL=subsL;
            }
            //cout<<"i s"<<endl;
            //cout<<i<<" "<<subsL<<endl;
        }
    return maxL;
    }
};

int main()
{
    Solution sol;
    
    cout << sol.lengthOfLongestSubstring("aba")<<endl;

    return 1;
}
