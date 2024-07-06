class Solution {
public:
     int totalWays(int index, int n, vector<int>&nums, int target,map<pair<int,int>,int>&m){
        if(index==n and target == 0) return 1;
        if(index==n and target!=0) return 0;
        pair<int,int>p = {index,target};
        if(m.find(p)!=m.end()) return m[p];
        int consider = totalWays(index+1,n,nums,target-nums[index],m);
        int notConsider = totalWays(index+1,n,nums,target+nums[index],m);
        return m[p] = (consider+notConsider);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int>m;
        return totalWays(0,n,nums,target,m);
    }
};