class Solution {
public:
    int Profit(int index,int n,vector<int>&prices,int canBuy,int transactionTracker, map<pair<pair<int,int>,int>,int>&dp){
        if(index>=n || transactionTracker == 0)
            return 0;
        
        pair<int,int> p = {index,transactionTracker};
        pair<pair<int,int>,int> currentKey = {p,canBuy};
        if(dp.find(currentKey)!=dp.end())
            return dp[currentKey];
        
        if(canBuy == 1){
        int idle = Profit(index+1,n,prices,canBuy,transactionTracker,dp);
        int Buy = -prices[index] + Profit(index+1,n,prices,0,transactionTracker,dp);
        dp[currentKey] = max(idle,Buy);
        return dp[currentKey];
        }
        
        else{
        int idle = Profit(index+1,n,prices,canBuy,transactionTracker,dp);
        int Sell = prices[index] + Profit(index+1,n,prices,1,transactionTracker-1,dp); 
        dp[currentKey] = max(idle,Sell);
        return dp[currentKey];
        }
    }
    int maxProfit(int k , vector<int>& prices){
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        map<pair<pair<int,int>,int>,int>dp;
        return Profit(0,prices.size(),prices,1,k,dp);
    }
};