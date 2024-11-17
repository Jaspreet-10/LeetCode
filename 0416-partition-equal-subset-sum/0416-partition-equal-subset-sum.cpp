class Solution {
public:
    bool findSubsets(int k, int index, int n, vector<int> &arr,
     vector<vector<int>>&dp){
    if(k == 0) return true;
    if(k<0 || index>=n) return false;
    if(dp[index][k]!=-1) return dp[index][k];
    bool take = false;
    if(arr[index]<=k)
    take =  findSubsets(k-arr[index],index+1, n, arr,dp);
    if(take) return true;
    bool notTake = findSubsets(k, index+1, n, arr, dp);
    dp[index][k] = take or notTake;
    return take or notTake;
}
    bool canPartition(vector<int>& nums) {
        int totSum = 0, n = nums.size();
        for(int i = 0 ; i < n ; ++i) totSum+=nums[i];
        if(totSum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(totSum,-1));
        return findSubsets(totSum/2, 0, n,nums, dp);
    }
};