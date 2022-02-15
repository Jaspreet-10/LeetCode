class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
           for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1])
                i++;
            else{
                v.push_back(nums[i]);
            }
        }
        if(v.size()!=2)
            v.push_back(nums[nums.size()-1]);
        return v;
    }
};