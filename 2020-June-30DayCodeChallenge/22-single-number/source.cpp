#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>

#define log(A) std::cout<<A<<std::endl

class Solution
{
public:
    int singleNumber(std::vector<int>& nums) {
        static const int INT = 32;
        int bitC[INT];                      // vector of 32 bits 

        for (std::size_t i =0; i<32;i++)    // initialise the vector
            bitC[i]=0;

        for (std::size_t i =0; i<32;i++)
        {
            int bMask = 1<<i;
            for (auto j : nums)
                if ( j & bMask)
                    bitC[i]++;
        }

        int sol =0;

       for (std::size_t i =0; i<32;i++) 
           if(bitC[i]%3!=0)
               sol += 1<<i;

        return sol;
        
    }
};

int main()
{
    Solution s;
    std::vector<int> temp={1,1,1,4};
    std::cout<<s.singleNumber(temp);
    log("");

	return 1;
}
