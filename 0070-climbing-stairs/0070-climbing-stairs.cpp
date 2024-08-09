class Solution {
public:
    int countTheSteps(int index, int n, vector<int>&dp){
        if(index == n) return 1;
        if(index>n) return 0;
        if(dp[index]!=0) return dp[index];
        dp[index] = countTheSteps(index+1,n,dp) + countTheSteps(index+2,n,dp);
        return dp[index];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1);
        return countTheSteps(0,n,dp);
    }
};