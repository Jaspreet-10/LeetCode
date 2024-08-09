class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, add = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            sum+=i;
            add+=nums[i];
        }
        sum+=nums.size();
        return sum-add;
    }
};