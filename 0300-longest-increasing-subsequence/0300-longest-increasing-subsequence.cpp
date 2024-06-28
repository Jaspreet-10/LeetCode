class Solution {
public:
    int longestSub(int index, int prevIndex, vector<int>&nums, vector<vector<int>>&dp){
        if(index == nums.size()) return 0;
        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];
        int take = 0;
        if(prevIndex == -1 || nums[index]>nums[prevIndex]){
            take = 1+longestSub(index+1,index,nums,dp);
        }
        int notTake = longestSub(index+1,prevIndex,nums,dp);
        dp[index][prevIndex+1] = max(take, notTake);
        return dp[index][prevIndex+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return longestSub(0,-1,nums,dp);
    }
};