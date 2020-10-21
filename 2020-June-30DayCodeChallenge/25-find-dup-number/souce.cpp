#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findDuplicate(std::vector<int> nums) 
    {
        std::sort(nums.begin(),nums.end());
        for (unsigned long i =0; i< nums.size()-1;i++)
        {
            if (nums[i]==nums[i+1])
                return nums[i];
        }
        return 0;
    }
};

int main()
{

    Solution s;
    std::vector<int> temp = {1,3,5,2,2};
    std::cout<<s.findDuplicate(temp);
    return 0;

}
