class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),count=0;
        vector<int>v;
        for(int i=0;i<n;++i){
            if(nums[i]==target){
                int count=0;
                v.push_back(i);
                while(i<n and target==nums[i]){
                    count++;
                    i++;
                }
                    v.push_back(i-1);
                break;
            }
        }
        if(v.empty())
            return v={-1,-1};
        return v;
    }
};