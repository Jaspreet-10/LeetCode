class Solution {
public:
    int trans(int index, int n, vector<int>&prices, vector<vector<int>>&dp, bool canBuy){
        if(index >= n) return 0;
        if(dp[index][canBuy]!=-1) return dp[index][canBuy];
        int idle = 0, profit = 0;
        if(canBuy){
            idle = trans(index+1,n,prices,dp,canBuy);
            profit = -prices[index] + trans(index+1,n,prices,dp,false);
        }else{
            idle = trans(index+1,n,prices,dp,canBuy);
            profit = prices[index] + trans(index+2,n,prices,dp,true);
        }
        return dp[index][canBuy] =  max(idle, profit);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return trans(0,n,prices,dp,true);
    }
};