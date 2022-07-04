class Solution {
public:
    int minimumPathSum(int Crow,int Ccol,int row,int col,vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(Crow==row-1 and Ccol==col-1)
            return grid[Crow][Ccol];
        
        if(Crow>=row || Ccol>=col){
            return 10001;
        }
        
        if(dp[Crow][Ccol]!=-1)
            return dp[Crow][Ccol];
        
        int down = grid[Crow][Ccol] + minimumPathSum(Crow+1,Ccol,row,col,grid,dp);
        int right = grid[Crow][Ccol] + minimumPathSum(Crow,Ccol+1,row,col,grid,dp);
        dp[Crow][Ccol] = min(down,right);
        return dp[Crow][Ccol];
    }
    int minPathSum(vector<vector<int>>& grid){
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return minimumPathSum(0,0,grid.size(),grid[0].size(),grid,dp);
    }
};