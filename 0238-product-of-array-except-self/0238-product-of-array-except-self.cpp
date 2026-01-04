class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zero = 0, n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0)++zero;
            else
            prod*=nums[i];
        }
        cout<<prod;
        if(zero>1){
            vector<int>ans(n, 0);
            return ans;
        }
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0) nums[i] = prod;
            else if(zero>0 and nums[i]!=0) nums[i] = 0;
            else nums[i] = prod/nums[i];
        }
        return nums;
    }
};