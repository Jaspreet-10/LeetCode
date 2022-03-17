class Solution {
public:
    int minCost(int index,vector<int>&cost,int n,unordered_map<int,int>&memo){
        if(index==n)
            return 0;
        if(index>n)
            return 1000;//maximum depends on the cpst array. Here max cost is 999.
        int currentKey=index;
        if(memo[currentKey]>0)
            return memo[currentKey];
        int oneJump=cost[index]+minCost(index+1,cost,n,memo);
        int twoJumps=cost[index]+minCost(index+2,cost,n,memo);
        memo[currentKey]=min(oneJump,twoJumps);
        return memo[currentKey];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>memo;
        return min(minCost(0,cost,cost.size(),memo),memo[1]);
    }
};