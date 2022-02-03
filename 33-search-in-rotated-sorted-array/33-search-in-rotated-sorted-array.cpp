class Solution {
public:
    int helper(vector<int>nums,int low,int high,int target){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(low>high)
            return -1;
        if(nums[mid]>target){
            return helper(nums,low,mid-1,target);
        }
        else{
            return helper(nums,mid+1,high,target);
        }
       return -1;
    }
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(nums[i]>nums[j]){
            i++;
        }
        int ans=-1;
        if(nums[i]==target) return i;
        if(target>=nums[i] and target<=nums[j]){
        ans=helper(nums,i,j,target);
        }
        else{
           ans=helper(nums,0,i,target);
        }
        return ans;
    }
};