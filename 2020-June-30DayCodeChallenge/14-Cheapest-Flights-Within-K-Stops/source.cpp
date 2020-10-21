#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:


//    template <class T>

//    void PrintM (std::vector <std::vector<T>>& mat)
//    {
//        for (std::vector<T> i : mat)
//        {
//            for ( T j : i)
//                std::cout<<j<<" ";
//            std::cout<<std::endl;
//        }
//        return;
//    }

    int findCheapestPrice (int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) 
    {
        std::vector<std::vector <int>> values;
        int max = -1;
        for (int i=0;i<n;i++)
        {
            std::vector <int> temp(n,0);
            values.push_back(temp);
        }

        for (std::vector<int> tempV : flights)
        {
            int from = tempV[0];
            int to = tempV[1];
            int cost= tempV[2];
            values[from][to]=cost;
        }

        std::queue <int> q;
        std::queue <int> qV;

        int j;
        int steps = K;
        steps += 1;
        q.push(dst);
        qV.push(0);
        
        int level=1;
        int costC;
        int nextLevel=0;
        int min = -1;

        while (steps && !q.empty() )
        {

            costC=qV.front();
            j=q.front();
            q.pop();
            qV.pop();
            level --;


            for (int i=0;i<n;i++)
            {
                int cost = values[i][j];
                if (cost)
                {
                    cost+=costC;
                    if(i==src)
                    {
                        if(min==-1 || min>cost)
                            min=cost;
                    }
                    else
                    {
                        q.push(i);
                        qV.push(cost);
                        nextLevel++;
                    }
                }
            }            

            if(level==0)
            {
                level=nextLevel;
                nextLevel=0;
                steps--;
            }

        }
//        PrintM(values);

        return min;
    }

};

int main ()
{
    Solution s;
    int n =3;
    std::vector<std::vector <int>> flight = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0;
    int dst = 2;
    int K =3 ;
    std::cout<<s.findCheapestPrice(n,flight,src,dst,K)<<std::endl;
    return 0;
}
