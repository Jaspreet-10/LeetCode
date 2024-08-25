class Solution {
public:
    int robberHelper(int index, vector<int>&nums, int n, vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int consider = nums[index] + robberHelper(index+2, nums, n, dp);
        int notConsider = robberHelper(index+1, nums, n, dp);
        return dp[index] = max(consider, notConsider);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return robberHelper(0, nums, n, dp);
    }
};