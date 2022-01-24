class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),count=0,i=0,j=0,prod=1;
        if(k<=1){
            return 0;
        }
            while(i<n){
                prod*=nums[i];
                while(prod>=k){
                    prod/=nums[j];
                    j++;
                }
                count=count+i-j+1;
                i++;
            }
        return count;
    }
};