class Solution {
public:
    int binarySearch(int start, int end, vector<int>&nums, int target){
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>target){
                return binarySearch(start, mid-1,nums,target);
            }else{
                 return binarySearch(mid+1,end,nums,target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int lengthOfNums = nums.size();
        return binarySearch(0,lengthOfNums-1,nums,target);
    }
};