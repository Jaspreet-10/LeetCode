class Solution {
public:
    int minCoins(int i, int n, vector<int>&coins, int amount, vector<vector<int>>&dp){
        if(amount == 0) return 0;
        if(amount<0 || i >= n) return 10001;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int consider = 1 + minCoins(i, n, coins, amount-coins[i], dp);
        int notConsider = minCoins(i+1, n, coins, amount, dp);
        dp[i][amount] = min(consider, notConsider);
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = minCoins(0, n, coins, amount, dp);
        if(ans == 10001) return -1;
        return ans;
    }
};