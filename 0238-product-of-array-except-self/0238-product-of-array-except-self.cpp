class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, count = 0, n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0) ++count;
            else
            prod*=nums[i];
        }
        if(count>1){
            vector<int>v(n, 0);
            return v;
        }
        for(int i = 0 ; i < n ; ++i){
            if(nums[i]!=0 and count == 1) nums[i] = 0;
            else if(nums[i] == 0) nums[i] = prod;
            else{
                nums[i] = prod/nums[i];
            }
        }
        return nums;
    }
};