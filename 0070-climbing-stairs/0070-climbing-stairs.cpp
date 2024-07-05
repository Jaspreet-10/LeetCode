class Solution {
public:
    int countStairs(int steps, int n, vector<int>&dp){
        if(steps>n) return 0;
        if(steps == n){
            return 1;
        }
        if(dp[steps]!=-1) return dp[steps];
        int oneSteps = countStairs(steps+1,n,dp);
        int twoSteps = countStairs(steps+2,n,dp);
        dp[steps] = oneSteps+twoSteps;
        return dp[steps];
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return countStairs(0,n,dp);
    }
};