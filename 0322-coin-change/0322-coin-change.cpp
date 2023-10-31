class Solution {
public:
    int findMinimumCoins(int index, vector<int>&coins, int amount, vector<vector<int>>&dp){
        if(amount == 0){
            return 0;
        }
        if(index>=coins.size() or amount<0) return 10001;
        
        if(dp[index][amount]!=-1) return dp[index][amount];
        int consider = 10001;
        if(amount>=coins[index])
        consider = 1 + findMinimumCoins(index, coins, amount-coins[index],dp);
        int notConsider = findMinimumCoins(index+1, coins, amount,dp);
        dp[index][amount] = min(consider,notConsider);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
           int ans = findMinimumCoins(0, coins, amount, dp);
           if(ans == 10001) return -1;
           return ans;
    }
};