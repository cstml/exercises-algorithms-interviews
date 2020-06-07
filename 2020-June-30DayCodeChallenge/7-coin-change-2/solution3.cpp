class Solution {
public:
    int change(int amount, vector<int> &coins) 
    {
        vector<int> top;
        int i;
        for (i=0;i<=amount;i++)
            top.push_back(0);
        top[0]=1;
        for (i=0;i< coins.size();i++)
            FillPosition(top,coins[i],amount);
        return top[amount];
    }
    
    void FillPosition(vector<int> &top, int val,int max)
    {
        for (int i; i<=max;i++)
        {
            if (i-val>=0)
                top[i]+=top[i-val];
        }
        return;
    }
};

