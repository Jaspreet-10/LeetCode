class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, count = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == 0){
                ++count;
            }else
            prod*=nums[i];
        }
        if(count>1){
            return vector<int>(nums.size(), 0);
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == 0){
                nums[i] = prod;
            }
            else if(count>0){
                nums[i] = 0;
            }
            else{
                nums[i] = prod/nums[i];
            }
        }
        return nums;
    }
};