class Solution {
public:
    int change(int amount, vector<int> coins) 
    {
        int pos=0;
        if (amount==0)
            return pos += 1;
        else if (amount<0)
            return 0;
        
        while (!coins.empty())
        { 
            int coin = coins.front();
            pos += change(amount-coin,coins);
            coins.erase(coins.begin());
        }
        return pos;
    }
};

