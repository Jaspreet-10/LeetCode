class Solution {
public:
//     TC ->O(n*target*f)
//     SC -> O(n*target)
    int totalWays(int n,int k,int target,vector<vector<int>>&dp){
        if(target == 0 and n==0)
            return 1;
        
        if(n==0 || target <= 0)
            return 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
//         (a+b)%c = (a%c + b%c)%c
//         (ways+tempAns)%MOD
        int ways=0,MOD=1e9+7;//We are intializing way = 0 beacuse from every node we need to get 
//                             different ways, like count works for every duplicate elements in the
//                              two for loops. we need to intialize count =0 in first loop again and again for diffrent elemnets, this is how ways is working ony recursion is taking care of thw ways here
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