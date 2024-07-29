class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleNumber = 0, doubleNumber = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i]<=9){
                singleNumber+=nums[i];
            }else{
                doubleNumber+=nums[i];
            }
        }   
        if(singleNumber!=doubleNumber) return true;
        return false;
    }
};