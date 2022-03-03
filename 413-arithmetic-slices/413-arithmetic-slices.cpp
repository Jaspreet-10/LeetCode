class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;++i){
                int diff=nums[i+1]-nums[i],count=0;
            for(int j=i;j<nums.size()-1;++j){
                    if(nums[j+1]-nums[j]==diff)
                        ++count;
                    else
                        break;
                    if(count>=2)
                        ++ans;
            }
        }
        return ans;
    }
};