class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        int i = 0 , j = nums.size()-1;
        while(i<=j){
            if(nums[i]%2!=0 and nums[j]%2==0){
                swap(nums[i],nums[j]);
                ++i;
                --j;
            }
            if(nums[j]%2!=0){
                --j;
            }
            if(nums[i]%2==0){
                ++i;
            }
        }
        return nums;
    }
};