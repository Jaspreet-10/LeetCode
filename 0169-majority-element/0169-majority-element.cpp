class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, maxi = nums[0];
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i]!=maxi) --count;
            else ++count;
            if(count == 0){
                maxi = nums[i];
                ++count;
            }
        }
        return maxi;
    }
};