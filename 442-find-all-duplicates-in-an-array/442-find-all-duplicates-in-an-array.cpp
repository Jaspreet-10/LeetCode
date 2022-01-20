class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();++i){
            if(m[nums[i]]==0)
                m[nums[i]]=1;
            else
                v.push_back(nums[i]);
        }
        return v;
    }
};