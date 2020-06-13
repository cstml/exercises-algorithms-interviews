#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
public:
    template<typename T>
    void PrintV (std::vector<T>& a)
    {
        for (T i : a)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
    {
        unsigned int sz = nums.size();

        if (sz<=1)
            return nums;

        std::vector<int> val(sz,1);
        std::vector<int> prevInd(sz,-1);

        int maxV = 0;
        unsigned int maxP = 0;
        std::sort(nums.begin(),nums.end());

        for ( unsigned int i = 1 ; i< sz ; i++)
        {
            for (unsigned int j = 0; j<i;j++)
            {
                if (nums[i]%nums[j]==0 && val[j]>=val[i])
                {
                    val[i] =val[i]+1;
                    prevInd[i]=j;
                }
                if (maxV<val[i])
                {
                    maxV = val[i];
                    maxP = i;
                }
            }
        }
        PrintV(nums);
        PrintV(val);
        PrintV(prevInd);

        std::vector <int> temp;
        temp.push_back(nums[maxP]);

        while (prevInd[maxP]!=-1)
        {
            maxP=prevInd[maxP];
            temp.insert(temp.begin(),nums[maxP]);
        }
        nums=temp;
        return nums;
    }

};

int main()
{

    std::vector <int> vec={1,2,3,4};
    Solution s;
    s.largestDivisibleSubset(vec);

    for (auto i : vec)
        std::cout<<i;
    std::cout<<"\n";

    return 0;
}
