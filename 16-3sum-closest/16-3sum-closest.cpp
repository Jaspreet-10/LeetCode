class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),diff=0,min=0,diff_main=INT_MAX;
        for(int i=0;i<n-2;++i){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>target)
                diff=sum-target;
                else
                diff=target-sum;
                if(diff<0)
                    diff*=-1;
                if(diff<diff_main){
                    diff_main=diff;
                    min=sum;
                }
                // if(sum==target)
                //     return 0;
                else if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return min;
    }
};