// solution using Lagrange's four square theorem
//
#include <iostream>
#include <queue>
#include <math.h>
#include <vector>

#define log(a) std::cout<<a<<std::endl

class Solution 
{
public:
    int numSquares(int n) 
    {
        std::vector <int> test;
        std::vector <int> next;
        for (int i=1;i*i<=n;i++)
        {
            test.push_back(i*i);
        }

        for (unsigned int i =0 ;i<test.size();i++)
            if (test[i]==n)
                return 1;

        for (unsigned int i =0 ;i<test.size();i++)
            for (unsigned int j =0 ;j<test.size();j++)
                if (test[i]+test[j]==n)
                    return 2;

        for (unsigned int i =0 ;i<test.size();i++)
            for (unsigned int j =0 ;j<test.size();j++)
                for (unsigned int k =0 ;k<test.size();k++)
                    if (test[i]+test[j]+test[k]==n)
                        return 3;
        return 4;
    }
};

int main()
{
    Solution s;
    int b=s.numSquares(12);
    log(b);
    return 1;
}
