class Solution {
public:
    bool helper(int index, int n, int sum, vector<int>&nums, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(index>=n || sum<0) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool consider = helper(index+1, n, sum-nums[index], nums, dp);
        bool notConsider = helper(index+1, n, sum, nums, dp);
        return dp[index][sum] = consider or notConsider;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0 ; i < nums.size() ; ++i) sum+=nums[i];
        if(sum%2 != 0) return false;
        sum/=2;
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return helper(0, n, sum, nums, dp);
    }
};