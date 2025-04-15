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
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(helper(0, n-1, dp1, nums), helper(1, n, dp2, nums));
    }
};