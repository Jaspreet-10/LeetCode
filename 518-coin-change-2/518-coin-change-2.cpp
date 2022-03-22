class Solution {
public:
    long long totalWays(int amount,vector<int>& coins,int index,int n,map<pair<int,int>,int>&memo){
        if(amount==0)
            return 1;
        if(index>=n)
            return 0;
        pair<int,int>currentKey={index,amount};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int consider=0;
        if(coins[index]<=amount)
            consider=totalWays(amount-coins[index],coins,index,n,memo);
        int notConsider=totalWays(amount,coins,index+1,n,memo);
        memo[currentKey]=consider+notConsider;
        return memo[currentKey];
    }
    int change(int amount, vector<int>& coins) {
        map<pair<int,int>,int>memo;
        // memset(dp,-1,sizeof(dp));//Time Taken is O(n).
        return totalWays(amount,coins,0,coins.size(),memo);
    }
};