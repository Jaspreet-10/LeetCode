class Solution {
public:
    int countTheSteps(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index == n-1) return cost[index];
        if(index>=n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneJump = cost[index] + countTheSteps(index+1,n,dp,cost);
        int twoJump = cost[index] + countTheSteps(index+2,n,dp,cost);
        dp[index] = min(oneJump,twoJump);
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1);
        return min(countTheSteps(0,n,dp,cost),countTheSteps(1,n,dp,cost));
    }
};