class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])
            return 0;
        for(int i = 0 ; i < nums.size()-1 ; ++i){
            if(nums[i]==target)
                return i;
            if(target>nums[i] and target<nums[i+1])
                return i+1;
        }
        if(nums[nums.size()-1]==target)
            return nums.size()-1;
        return nums.size();
    }
};