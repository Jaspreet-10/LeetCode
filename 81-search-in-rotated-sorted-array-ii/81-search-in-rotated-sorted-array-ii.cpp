class Solution {
public:
    bool biSearch(int low,int high,vector<int>nums,int target){
        if(low<high){
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] > target)
                return biSearch(low,mid,nums,target);
            else
              return biSearch(mid+1,nums.size(),nums,target);
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int i=0,n=nums.size();
        for(i=0;i<n-1;++i){
            if(nums[i] == target)
                return true;
            if(nums[i+1]<nums[i])
                break;
        }
            if(nums[i] == target)
                return true;
        
            else if(target<nums[i])
                return biSearch(i+1,n,nums,target);
            else
                return biSearch(0,i,nums,target);
        return false;
    }
};