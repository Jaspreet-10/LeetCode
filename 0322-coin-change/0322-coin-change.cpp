class Solution {
public:
     int climbStairsHelper(int index, int n, map<pair<int,int>,int>&m, vector<int>&coins,
     int amount){
        if(amount == 0) return 0;
        if(index >= n || amount<0) return 10001;
        if(m[{index, amount}]>0) return m[{index,amount}];
        int consider = 1 + climbStairsHelper(index,n,m,coins,amount-coins[index]);
        int notConsider = climbStairsHelper(index+1,n,m,coins,amount);
        return m[{index, amount}] = min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        map<pair<int,int>,int>m;
        int n = coins.size();
        int ans = climbStairsHelper(0,n,m,coins,amount);
        if(ans == 10001) return -1;
        return ans;
    }
};