class Solution {
public:
    int Profit(int index,int n,vector<int>&prices,int canBuy,int transactionTracker, vector<vector<int>>&dp){
        if(index>=n)
            return 0;
        
        if(dp[index][canBuy]!=-1)
            return dp[index][canBuy];
        
        if(canBuy == 1){
        int idle = Profit(index+1,n,prices,canBuy,1,dp);
        int Buy = -prices[index] + Profit(index+1,n,prices,0,1,dp);
        dp[index][canBuy] = max(idle,Buy);
        return dp[index][canBuy];
        }
        
        else{
        int idle = Profit(index+1,n,prices,canBuy,1,dp);
        int Sell = prices[index] + Profit(index+1,n,prices,1,0,dp); 
        dp[index][canBuy] = max(idle,Sell);
        return dp[index][canBuy];
        }
    }
    int maxProfit(vector<int>& prices){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return Profit(0,prices.size(),prices,1,1,dp);
    }
};