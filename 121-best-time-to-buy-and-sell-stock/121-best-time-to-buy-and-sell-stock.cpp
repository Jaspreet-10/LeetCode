class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int bp=INT_MAX,sp=INT_MAX,max_sell=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<bp){
                bp=nums[i];
            }
            if(nums[i]>bp){
                if(nums[i]-bp>max_sell){
                    max_sell=nums[i]-bp;
                }
            }
        }
        return max_sell;
    }
};