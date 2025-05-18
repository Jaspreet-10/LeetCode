class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(i<n && j<n){
            if(nums[i] == 0 and nums[j]!=0 and i<j){
                swap(nums[i++], nums[j++]);
            }
            else if(nums[i] != 0){
                ++i;
            }
            else
            ++j;
        }
        return ;
    }
};