class Solution {
public:
    int helper(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index>=n) return 0;
        if(dp[index]!=1001) return dp[index];
        int oneStep = cost[index] + helper(index+1, n, dp, cost);
        int twoStep = cost[index] + helper(index+2, n, dp, cost);
        return dp[index] = min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,1001);
        return min(helper(0, n, dp, cost), dp[1]);
    }
};