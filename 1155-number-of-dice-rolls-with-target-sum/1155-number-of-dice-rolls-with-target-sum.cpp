class Solution {
public:
    int totalWays(int n,int k,int target,vector<vector<int>>&dp){
        if(target == 0 and n==0)
            return 1;
        
        if(n==0 || target <= 0)
            return 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int ways=0,MOD=1000000007;
        for(int i=1;i<=k;++i){
            int tempAns = totalWays(n-1,k,target - i, dp)%MOD;
            ways = ways % MOD;
            ways = (ways+tempAns)%MOD;
            dp[n][target] = ways;
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return totalWays(n,k,target,dp);
    }
};