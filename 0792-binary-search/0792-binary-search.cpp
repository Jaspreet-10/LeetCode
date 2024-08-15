class Solution {
public:
    int binarySearch(int low, int high, vector<int>&nums, int target){
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                high  = mid-1;
            }else low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        return binarySearch(0,high,nums,target);
    }
};