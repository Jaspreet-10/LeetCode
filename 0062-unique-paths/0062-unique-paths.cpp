class Solution {
public:
    int numberOfWays(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i == m-1 and j == n-1) return 1;
        if(i>=m || j>=n || i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = numberOfWays(i+1,j,m,n,dp) + numberOfWays(i,j+1,m,n,dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return numberOfWays(0,0,m,n,dp);
    }
};