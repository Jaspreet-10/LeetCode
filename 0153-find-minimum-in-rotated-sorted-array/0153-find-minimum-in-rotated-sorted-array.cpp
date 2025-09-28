class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[0] and nums[0]>nums[high]) low = mid+1;
            else high = mid;
        }
        return nums[low];
    }
};