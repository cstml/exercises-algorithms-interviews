#include <map>
#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) 
    {
        std::map<int,int> m;
        std::pair<std::map<int,int>::iterator,bool> it;
        for (unsigned long i =0; i< nums.size();i++)
        {
            it=m.insert(std::pair<int,int>(nums[i],nums[i]));
            if (it.second == false)
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
