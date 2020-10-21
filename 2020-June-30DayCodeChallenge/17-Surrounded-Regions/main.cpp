#pragma once
#include <vector>
#include "Matrix.cpp"
#include <queue>
#define troubleshooting 1

#if troubleshooting
#define Log(a) std::cout<<a<<endl;
#else 
#define Log(a) 
#endif


using namespace std;
class Solution {
public:
    unsigned int szi;
    unsigned int szj;
    
    void Fill(vector<vector<char>>& board,int i,int j, char search, char replace)
    {
        board[i][j]=replace;

        if(i+1<szi && board[i+1][j]==search)
            Fill(board,i+1,j,search,replace);
        
        if(i-1>0 && board[i-1][j]==search)
            Fill(board,i-1,j,search,replace);
        
        if(j+1<szj && board[i][j+1]==search)
            Fill(board,i,j+1,search,replace);

        if(j-1>0 && board[i][j-1]==search)
            Fill(board,i,j-1,search,replace);

        return;
    }
    void solve(vector<vector<char>>& board)
    {
        if (!board.size())
            return;
        szi = board.size();
        szj = board[0].size();
        char search='O';
        char replace='t';
        for (unsigned int i=0;i < szi;i++)
        {
            log(board[i][0]);
            if(board[i][0] == search)
                Fill (board,i,0,search,replace);

            if(board[i][szj-1] == search)
                Fill (board,i,szj-1,search,replace);
        }

        for (unsigned int j=0;j < szj;j++)
        {
            if(board[0][j] == search)
                Fill (board,0,j,search,replace);

            if(board[szi-1][j] == search)
                Fill (board,szi-1,j,search,replace);
        }
        
        search = 'O';
        replace = 'X';
        for (unsigned int i = 1 ; i <szi-1; i++)
        {
            for (unsigned int j = 1; j <szj-1;j++)
            {
                if(board[i][j]==search)
                    Fill(board,i,j,search,replace);
            }
        }
        
        search='t';
        replace='O';
        for (unsigned int i=0;i < szi;i++)
        {
            log(board[i][0]);
            if(board[i][0] == search)
                Fill (board,i,0,search,replace);

            if(board[i][szj-1] == search)
                Fill (board,i,szj-1,search,replace);
        }

        for (unsigned int j=0;j < szj;j++)
        {
            if(board[0][j] == search)
                Fill (board,0,j,search,replace);

            if(board[szi-1][j] == search)
                Fill (board,szi-1,j,search,replace);
        }
    }
};

