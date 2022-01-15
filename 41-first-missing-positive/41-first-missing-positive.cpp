class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),v=0;
        if(n==1){
            if(nums[0]==1)
                return 2;
            return 1;
        }
        for(int i=0;i<n-1;++i){
         if(nums[i]==1)
             v=-1;
         if(nums[i+1]>=0 and nums[i]>=0)
         if(nums[i+1]-nums[i]>1 and v!=0)
             return nums[i]+1;
        }
        if(nums[n-1]==1) v=-1;
        if(nums[n-1]>=0 and nums[n-2]>=0)
        if(nums[n-1]-nums[n-2]>1 and v!=0)
            return nums[n-2]+1;
        if(v==0) return 1;
        return nums[n-1]+1;
    }
};