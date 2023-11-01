class Solution {
public:
    int maxAmount(int index, vector<int>&nums, vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }
        int consider = nums[index]+maxAmount(index+2,nums,dp);
        int notConsider = maxAmount(index+1,nums,dp);
        dp[index] = max(consider, notConsider);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
         return nums[0];
        vector<int>dp(nums.size(),-1);
        return max(maxAmount(0,nums,dp),dp[1]);
    }
};