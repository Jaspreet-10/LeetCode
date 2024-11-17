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
        unordered_map<int,int>m1,m2;
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(climbStairsHelper(0,n-1,m1,nums), climbStairsHelper(1,n,m2,nums));
    }
};