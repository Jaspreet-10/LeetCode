class Solution {
public:
    int minimumCost(int index, vector<int>&cost, int n, unordered_map<int,int>&m){
        if(index>=n)
            return 0;
        if(m[index]>0) return m[index];
        int lh = cost[index] + minimumCost(index+1,cost,n,m);
        int rh = cost[index] + minimumCost(index+2,cost,n,m);
        m[index] = min(lh,rh);
        return m[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>m;
        return min(minimumCost(0,cost,cost.size(),m),m[1]);
    }
};