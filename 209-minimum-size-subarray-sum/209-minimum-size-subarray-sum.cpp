class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,count=INT_MAX,sum=0,n=nums.size();
        while(i<n){
        while(sum<target and i<n){
            if(nums[i]==target)
                return 1;
            sum+=nums[i];
            cout<<sum<<" ";
            i++;
        }
        while(j<i and sum>=target){
            if(sum>=target){
                count=min(count,i-j);
            }
            sum-=nums[j];
            cout<<sum<<" ";
            j++;
            }
        }
        if(count==INT_MAX)
            return 0;
        return count;
    }
};