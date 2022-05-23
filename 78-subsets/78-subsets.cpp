class Solution {
public:
    int totalSubset(int index,vector<int>nums,vector<vector<int>>&ans,vector<int>&bt){
        if(index>=nums.size()){
            ans.push_back(bt);
            return 0;
        }
        bt.push_back(nums[index]);
        totalSubset(index+1,nums,ans,bt);
        bt.pop_back();
        totalSubset(index+1,nums,ans,bt);
        return 0;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>bt;
        totalSubset(0,nums,ans,bt);
        return ans;
    }
};