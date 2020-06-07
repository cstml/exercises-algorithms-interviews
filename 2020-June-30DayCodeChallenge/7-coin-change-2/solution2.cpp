class Solution {
public:
    int change(int amount, vector<int> &coins) 
    {
        vector<int> top;
        vector<int> next;
        int i;
        for (i=0;i<=amount;i++)
        {
            top.push_back(0);
            next.push_back(0);
        }
        top[0]=1;
        // PrintV (top);
        for (i=0;i< coins.size();i++)
        {
            FillPosition(top,next,coins[i],amount);
            Transcribe (top,next,amount);
            // PrintV (top);
        }
        
        return top[amount];
    }
    
    void FillPosition(vector<int> &top,vector<int> &botom, int val,int max)
    {
        for (int i; i<=max;i++)
        {
            if (i-val>=0)
                botom[i]=top[i]+botom[i-val];
            else
                botom[i]=top[i];
        }
        return;
    }
    
    void Transcribe(vector<int> &top,vector<int> &botom,int max)
    {
        for (int i =0 ; i<=max;i++)
            top[i]=botom[i];
        return;
    } 
    // void PrintV (vector<int> vec)
    // {
    //     for (int i : vec)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
};

