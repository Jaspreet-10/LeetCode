class Solution {
public:
    int findUniquePaths(int cr, int cc, int row, int col, vector<vector<int>>&dp){
        if(cr==row-1 && cc==col-1) return 1;
        if(cr<0 || cc<0 || cr>=row || cc>=col) return 0;
        if(dp[cr][cc]!=-1) return dp[cr][cc];
        int down = findUniquePaths(cr+1,cc,row,col,dp);
        int right = findUniquePaths(cr,cc+1,row,col,dp);
        return dp[cr][cc] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findUniquePaths(0,0,m,n,dp);
    }
};