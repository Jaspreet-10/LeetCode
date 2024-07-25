class Solution {
public:
    int findUniquePaths(int cr, int cc, int row, int col, map<pair<int,int>,int>&dp){
        if(cr==row-1 && cc==col-1) return 1;
        if(cr<0 || cc<0 || cr>=row || cc>=col) return 0;
        if(dp[{cr,cc}]>0) return dp[{cr,cc}];
        int down = findUniquePaths(cr+1,cc,row,col,dp);
        int right = findUniquePaths(cr,cc+1,row,col,dp);
        dp[{cr,cc}] = down+right;
        return down+right;
    }
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int>dp;
        return findUniquePaths(0,0,m,n,dp);
    }
};