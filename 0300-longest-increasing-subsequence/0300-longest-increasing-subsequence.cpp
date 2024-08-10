class Solution {
public:
    int maxLengthOfLIS(int index, vector<int>&nums, vector<vector<int>>&dp, int prev){
        if(index>=nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int consider = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            consider = 1 + maxLengthOfLIS(index+1, nums, dp, index);
        }
        int notConsider = maxLengthOfLIS(index+1, nums, dp, prev);
        return dp[index][prev+1] = max(consider,notConsider);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return maxLengthOfLIS(0,nums,dp,-1);
    }
};