#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums)
    {
        std::sort(nums.begin(),nums.begin()+nums.size());
        return ;
    }
};

void printVec (std::vector<int> vec)
{
    for (int a : vec)
    {
        std::cout<<a;
    }
    return ;
}

int main()
{

    Solution s;
    std::vector <int> vec={2,0,2,1,1,0};
    s.sortColors(vec);
    printVec(vec);
}

