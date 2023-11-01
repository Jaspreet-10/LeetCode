class Solution {
public:
    int maximumCherry(int cRow1, int cCol1, int cCol2, int row, int col, 
    vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(cCol1 < 0 || cCol1>=col|| cCol2 < 0  || cCol2>=col) return INT_MIN;
        if(cRow1 == row-1){
            if(cCol1 == cCol2) return grid[row-1][cCol1];
            else return grid[row-1][cCol2]+grid[row-1][cCol1];
        }
        if(dp[cRow1][cCol1][cCol2]!=-1) return dp[cRow1][cCol1][cCol2];
        int maxi = INT_MIN;
        for(int dj=-1;dj<=1;dj++)
        {   
            for(int d2=-1;d2<=1;d2++)
            {
                int value=0;
                if(cCol1==cCol2)
                {
                    value=grid[cRow1][cCol1];
                }
                else
                {
                    value=grid[cRow1][cCol1]+grid[cRow1][cCol2];
                }
                value+=maximumCherry(cRow1+1,cCol1+dj,cCol2+d2,row,col,grid,dp);
                maxi=max(maxi,value);
                dp[cRow1][cCol1][cCol2] = maxi;
            }
        }
        return dp[cRow1][cCol1][cCol2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int cRow1 = 0, cCol1 = 0, cRow2 = 0, cCol2 = grid[0].size()-1,
        row = grid.size(), col = grid[0].size();
        vector<vector<vector<int>>>dp(row,vector<vector<int> >(col, 
        vector<int>(col,-1)));
        return maximumCherry(cRow1,cCol1, cCol2, row, col, grid,dp);
    }
};