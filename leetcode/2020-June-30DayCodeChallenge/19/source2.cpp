#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define log(a) std::cout<<a<<std::endl

struct Node{
    
    unsigned int index;
    Node *nxt;
    Node *prv;

    Node(unsigned int i)
        :index(i),nxt(nullptr),prv(nullptr){}
};

class Solution {
public:
    string longestDupSubstring(string S) {
        Node *mtrx[25];
        for (unsigned int i=0; i<S.size();i++)
        {
            mtrx[i]=nullptr;
        }

        for (unsigned int i=0; i<S.size();i++)
        {
            unsigned int ltr= int(S[i]-'a');
            auto c = mtrx[ltr];
            if (!c)
                c = new Node(i);
            else
            {
                while(c)
                    c=c->nxt;
                c->nxt = new Node (i);
            }
            log(ltr);
        }

        for (unsigned i =0; i<25;i++)
        {
            std::cout<<'a'+i<<" ";
            auto c = mtrx[i];
            while (c)
            {
                std::cout<<(c->index)<<"-";
                c=c->nxt;
            }
            log("");
        }
        return "s";
    }
};

int main()
{
    Solution s;
    s.longestDupSubstring("banana");
    return 0;
}
