class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            int element = nums[i];
            if(nums[i]>0 and nums[i]<n){
                int chair = element-1;
                if(element!=nums[chair]){
                swap(nums[chair],nums[i]);
                --i;
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(i+1 != nums[i]) return i+1;
        }
        return n+1;
    }
};