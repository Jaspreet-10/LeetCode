class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<n;++i){
           int diff=target-nums[i];
            if(m[diff]>0){
            return v={m[diff]-1,i};
            }else{
                m[nums[i]]=i+1;
            }
        }
        return v;
    }
};