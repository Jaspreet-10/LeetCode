class Solution {
public:
    unordered_map<int,int>m;
    int minCost(int index, int n, vector<int>&cost){
        if(index>=n){
            return 0;
        }
        if(m[index+1]!=0)
            return m[index+1];
        int oneStep = cost[index]+minCost(index+1,n,cost);
        int twoStep = cost[index]+minCost(index+2,n,cost);
        m[index+1] = min(oneStep,twoStep);
        return m[index+1];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCost(0,cost.size(),cost),minCost(1,cost.size(),cost));
    }
};