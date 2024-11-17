class Solution {
public:
    int climbStairsHelper(int index, int n, unordered_map<int,int>&m){
        if(index == n) return 1;
        if(index>n) return 0;
        if(m[index]>0) return m[index];
        int oneStep = climbStairsHelper(index+1, n, m);
        int twoSteps = climbStairsHelper(index+2, n, m);
        return m[index] = oneStep + twoSteps;
    }
    int climbStairs(int n) {
        unordered_map<int,int>m;
        return climbStairsHelper(0,n,m);
    }
};