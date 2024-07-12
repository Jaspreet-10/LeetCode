class Solution {
public:
    int binarySearch(int low, int high, vector<int>&nums, int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        cout<<mid<<" ";
        if(nums[mid] == target) return mid;
        if(nums[mid]<=target){
            return binarySearch(mid+1,high,nums,target);
        }else{
            return binarySearch(low,mid-1,nums,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        return binarySearch(0,high,nums,target);
    }
};