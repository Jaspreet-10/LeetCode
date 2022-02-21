class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;++i){
            int val=nums[i],count=0;
            while(i<n and nums[i]==val){
                count++;
                i++;
            }
            i-=1;
            if(count>n/2)
                return nums[i];
        }
        return nums[n-1];
    }
};