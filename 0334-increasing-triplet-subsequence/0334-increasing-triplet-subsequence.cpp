class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i]<first){
                first = nums[i];
            }else if(nums[i]>first and nums[i]<second){
                second = nums[i];
            }
            else if(first!=INT_MAX and second!=INT_MAX and nums[i]>second) return true;
        }
        return false;
    }
};