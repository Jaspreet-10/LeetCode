class Solution {
public:
     // int ans=INT_MAX;
     int totalWays(int amount,vector<int>& coins,int index,int n, vector<vector<int>>&dp){
        if(amount==0)
            return 0;
        if(index>=n)
            return 10001;
        // string currentKey=to_string(index)+"-"+to_string(amount);
        // if(memo.find(currentKey)!=memo.end())
        //     return memo[currentKey];
         if(dp[index][amount]!=-1)
             return dp[index][amount];
        int consider=10001;
        if(coins[index]<=amount)
            consider=1+totalWays(amount-coins[index],coins,index,n,dp);
        int notConsider=totalWays(amount,coins,index+1,n,dp);
        dp[index][amount]=min(consider,notConsider);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // memset(dp,-1,sizeof(dp));//Time Taken is O(n).
        int ans= totalWays(amount,coins,0,coins.size(),dp);
        if(ans==10001)
            return -1;
        return ans;
    }
};