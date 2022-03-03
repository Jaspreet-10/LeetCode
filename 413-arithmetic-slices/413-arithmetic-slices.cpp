class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0,j=0,i=2;
        for(i=2;i<nums.size();++i){
               if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                   ans+=(i-j-1);
               }else{
                   j=i-1;
               }
        }
        return ans;
    }
};