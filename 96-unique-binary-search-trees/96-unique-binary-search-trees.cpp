class Solution {
public:
    int findNumber(int n,vector<int>&dp){
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int ways = 0;
        for(int i=0;i<n;++i){
            ways+=findNumber(i,dp)*findNumber(n-i-1,dp);
        }
        dp[n] = ways;
        return ways;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return findNumber(n,dp);
    }
};