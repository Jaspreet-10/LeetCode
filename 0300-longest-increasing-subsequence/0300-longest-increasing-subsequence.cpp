class Solution {
public:
    int checkLIS(int index, int prev, int n, vector<int>&nums, vector<vector<int>>&dp){
        if(index>=n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int consider = 0;
        if(prev==-1 || nums[index]>nums[prev]){
            consider = 1+checkLIS(index+1, index, n, nums, dp);
        }
        int notConsider = checkLIS(index+1, prev, n, nums, dp);
        return dp[index][prev+1] = max(consider,notConsider);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return checkLIS(0, -1, n, nums, dp);
    }
};