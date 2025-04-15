class Solution {
public:
    int helper(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int oneStep = cost[index] + helper(index+2, n, dp, cost);
        int twoStep = helper(index+1, n, dp, cost);
        return dp[index] = max(oneStep,twoStep);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(0, n, dp, nums);
    }
};