class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid = 0;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(target<nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};