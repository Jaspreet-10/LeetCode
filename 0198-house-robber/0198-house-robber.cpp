class Solution {
public:
     int climbStairsHelper(int index, int n, unordered_map<int,int>&m, vector<int>&cost){
        if(index>=n) return 0;
        if(m.find(index)!=m.end()) return m[index];
        int oneStep = cost[index] + climbStairsHelper(index+2, n, m, cost);
        int twoSteps = climbStairsHelper(index+1, n, m, cost);
        return m[index] = max(oneStep,twoSteps);
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        return climbStairsHelper(0,n,m,nums);
    }
};