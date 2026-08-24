class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>&dp, 
    vector<vector<int>>&grid){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i<0 || j<0 || i>=m || j>=n) return 100001;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = grid[i][j] + helper(i+1, j, m, n, dp, grid);
        int right = grid[i][j] + helper(i, j+1, m, n, dp, grid);
        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp, grid);
    }
};