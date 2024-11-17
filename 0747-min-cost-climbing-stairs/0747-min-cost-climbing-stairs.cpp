class Solution {
public:
     int climbStairsHelper(int index, int n, unordered_map<int,int>&m, vector<int>&cost){
        if(index>=n) return 0;
        if(m[index]>0) return m[index];
        int oneStep = cost[index] + climbStairsHelper(index+1, n, m, cost);
        int twoSteps = cost[index] + climbStairsHelper(index+2, n, m, cost);
        return m[index] = min(oneStep,twoSteps);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>m;
        int n = cost.size();
        return min(climbStairsHelper(0,n,m,cost), m[1]);
    }
};