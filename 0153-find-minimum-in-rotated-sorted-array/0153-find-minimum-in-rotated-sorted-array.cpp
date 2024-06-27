class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left<right){
            int mid = left + (right-left)/2;//to avoid overflow as right will always
                                            // be greater than left in terms of indexes
            if(nums[mid]>nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[right];
    }
};