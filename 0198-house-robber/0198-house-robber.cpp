class Solution {
public:
    int maximumProfit(int index, int n, vector<int>&nums,vector<int>&dp){
        if(index >= n) return 0;
        if(dp[index]!=-1) return dp[index];
        int consider = nums[index]+maximumProfit(index+2,n,nums,dp);
        int notConsider = maximumProfit(index+1,n,nums,dp);
        dp[index] = max(consider,notConsider);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maximumProfit(0,n,nums,dp);
    }
};