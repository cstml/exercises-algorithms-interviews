class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int y = dungeon.size(); 
        if(y == 0) 
            return 0;    
        int x = dungeon[0].size();  
		
        vector<vector<int>>mat(y+1,vector<int>(x+1,INT_MAX));
		
        mat[y-1][x] = 1;
        mat[y][x-1] = 1;
        for(int i=y-1;i>=0;i--)
        {
            for(int j=x-1;j>=0;j--)
            {
                int val = min(mat[i+1][j],mat[i][j+1]) - dungeon[i][j];  
                mat[i][j] = max(1,val); 
            }
        }
        
        return mat[0][0];  // The first element contains the minimum health needed to rescue the princess.
    }
};
