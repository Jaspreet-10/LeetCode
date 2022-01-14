class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> bt(int start,vector<int>v,vector<int>nums){
        res.push_back(v);
        for(int i=start;i<nums.size();++i){
            v.push_back(nums[i]);
            bt(i+1,v,nums);
            v.erase(v.end()-1);
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        if(nums.size()==0)
            return res;
        res=bt(0,cur,nums);
        return res;
    }
};