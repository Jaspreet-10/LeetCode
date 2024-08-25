class Solution {
public:
    int findLengthOfLIS(int index, vector<int>&nums, int n, vector<vector<int>>&dp, int prev){
        if(index>=n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int consider = 0;
        if(prev == -1 || nums[index]>nums[prev]){
            consider = 1 + findLengthOfLIS(index+1, nums, n, dp, index);
        }
        int notConsider = findLengthOfLIS(index+1, nums, n, dp, prev);
        return dp[index][prev+1] = max(consider, notConsider);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findLengthOfLIS(0, nums, n, dp, -1);
    }
};