class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0, prod = 1;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == 0) ++countZero;
            else{
                prod*=nums[i];
            }
        }
        if(countZero > 1){
            vector<int>v(nums.size(),0);
            return v;
        }
        for(int i = 0 ; i < nums.size(); ++i){
            if(countZero == 1 && nums[i]!=0) nums[i] = 0;
            else if(countZero == 1 && nums[i] == 0)
                nums[i] = prod;
            else{
                nums[i] = prod/nums[i];
            } 
        }
        return nums;
    }
};