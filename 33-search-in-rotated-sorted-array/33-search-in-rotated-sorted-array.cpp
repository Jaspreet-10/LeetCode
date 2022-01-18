class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1&&nums[0]==target){
            return 0;
        }
        vector<int>::iterator it;
        it = std::find (nums.begin(), nums.end(), target);
        if(it!=nums.end()){
            return (it-nums.begin());
        }
        return -1;
    }
};