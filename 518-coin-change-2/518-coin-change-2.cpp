class Solution {
public:
    long long totalWays(int amount,vector<int>& coins,int index,int n,unordered_map<string,int>&memo){
        if(amount==0)
            return 1;
        if(index>=n)
            return 0;
        string currentKey=to_string(index)+"-"+to_string(amount);
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
        unordered_map<string,int>memo;
        // memset(dp,-1,sizeof(dp));//Time Taken is O(n).
        return totalWays(amount,coins,0,coins.size(),memo);
    }
};