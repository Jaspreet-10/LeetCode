class Solution {
public:
    int maxMoney(vector<int>&nums,int index, unordered_map<int,int>&m){
        if(index>nums.size())
            return 0;
        if(m.find(index)!=m.end())
            return m[index];
        int consider = 0;
        if(index<nums.size())
        consider = nums[index] + maxMoney(nums,index+2,m);
        int notConsider = maxMoney(nums, index+1,m);
        m[index] = max(consider,notConsider);
        return m[index];
    }
    int rob(vector<int>& nums) {
       unordered_map<int,int>m;
       return max(maxMoney(nums,0,m),m[1]);
    }
};