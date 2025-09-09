class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());//[0,1,2,3] = 4
        for(int i = 0 ; i < nums.size()-1 ; ++i){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};