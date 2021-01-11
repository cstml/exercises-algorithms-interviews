#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

#define log(A) std::cout<<A<<std::endl
#define ll long long



class Solution {
public:

    int sz_x;
    int sz_y;
    std::vector<std::vector<int>> tots;
    std::vector<std::vector<int>> maxMin;

    template <class P>
    void initMat (std::vector<std::vector<P>>& destMat ,P initInfo)
    {
        for (int i=0;i<sz_y;i++)
        {
            std::vector<P> tmp;
            for (int j=0 ; j<sz_x ; j++)
            {
                tmp.push_back(initInfo);
            }
            destMat.push_back(tmp);
        }
    }

    void goMat(int posx, int posy, const std::vector<std::vector<int>>& dungeon)
    {
        int actual = 0;
        int minC= dungeon[0][0];
        for (posy=0;posy<sz_y;posy++)
        {
            for (posx=0;posx<sz_x;posx++)
            {
                if(posy==0)
                {
                    actual += dungeon[posy][posx];
                    tots[posy][posx]=actual;

                    if (actual<minC)
                        minC = actual;

                    maxMin[posy][posx] = minC;
                }
                else
                {
                    actual = dungeon[posy][posx];
                    if (posx)
                    {
                        if(maxMin[posy-1][posx] > maxMin[posy][posx-1])
                        {
                            actual+=tots[posy-1][posx];
                            tots[posy][posx] = actual;

                            if (actual<maxMin[posy-1][posx])
                                maxMin[posy][posx] = actual;

                            else
                                maxMin[posy][posx] = maxMin[posy-1][posx];
                        }
                        else
                        {
                            actual+=tots[posy][posx-1];
                            tots[posy][posx] = actual;

                            if (actual<maxMin[posy][posx-1])
                                maxMin[posy][posx] = actual;

                            else
                                maxMin[posy][posx] = maxMin[posy][posx-1];
                        }
                    }
                    else
                    {
                        actual+=tots[posy-1][posx];
                        tots[posy][posx] = actual;

                        if (actual<maxMin[posy-1][posx])
                            maxMin[posy][posx] = actual;

                        else
                            maxMin[posy][posx] = maxMin[posy-1][posx];
                    }
                }
            }
        }
    }

    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) 
    {
        sz_x= dungeon[0].size();
        sz_y= dungeon.size();

        initMat(tots,0);
        initMat(maxMin,std::numeric_limits<int>::max());

        log("maxMin");
        PMat(maxMin);

        goMat(0,0,dungeon);

        log("Dungeon");
        PMat(dungeon);
        log("maxMin");
        PMat(maxMin);
        log("tots");
        PMat(tots);

        int mM = maxMin[sz_y-1][sz_x-1];
        if (mM>0)
            return 1;
        else
            return 1-maxMin[sz_y-1][sz_x-1];
    }

    template <class T>
    void PMat(std::vector<std::vector<T>> mat)
    {
        for (auto a: mat)
        {
            for (auto b: a)
            {
                std::cout<<b<<" ";
            }
            std::cout<<std::endl;
        }
    }
};


int main()
{
    Solution s;

    //std::vector<std::vector<int>> temp = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    std::vector<std::vector<int>> temp = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    log(s.calculateMinimumHP(temp));

	return 1;
}
