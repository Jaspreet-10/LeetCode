class Solution {
public:
    map<vector<int>,int>m;
    vector<vector<int>>powerSet(vector<int>& nums, vector<vector<int>>&ans,
    int index, vector<int>v){
        if(index>=nums.size()){
            // sort(v.begin(),v.end());
            // if(m[v] == 0)
            ans.push_back(v);
            // m[v]++;
            return ans;
        }
        v.push_back(nums[index]);
        powerSet(nums,ans,index+1,v);
        v.pop_back();
        while (index != nums.size() - 1 && nums[index] == nums[index + 1])
            index++;
        powerSet(nums,ans,index+1,v);
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        return powerSet(nums,ans,0,v);
        // return ans;
    }
};