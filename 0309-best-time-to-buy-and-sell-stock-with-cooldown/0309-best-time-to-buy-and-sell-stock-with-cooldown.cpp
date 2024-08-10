class Solution {
public:
    int trans(int index, int n, vector<int>&prices, vector<vector<int>>&dp, bool canBuy){
        if(index >= n) return 0;
        if(dp[index][canBuy]!=-1) return dp[index][canBuy];
        if(canBuy){
            int idle = trans(index+1,n,prices,dp,canBuy);
            int profit = -prices[index] + trans(index+1,n,prices,dp,false);
             dp[index][canBuy] = max(idle, profit);
        }else{
            int idle = trans(index+1,n,prices,dp,canBuy);
            int profit = prices[index] + trans(index+2,n,prices,dp,true);
            dp[index][canBuy] = max(idle, profit);
        }
        return dp[index][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return trans(0,n,prices,dp,true);
    }
};