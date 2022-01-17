class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=1,n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;++i){
            if(nums[i]!=nums[j]){
                return nums[i];
            }
            i++;
            j+=2;
        }
        return nums[n-1];
    }
};