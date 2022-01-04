class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it=find(nums.begin(),nums.end(),target);
        if(it!=nums.end()){
            return (it-nums.begin());
        }
        if(target<nums[0]){
            return 0;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<target and nums[i+1]>target){
                return i+1;
            }
        }
        return nums.size();
    }
};