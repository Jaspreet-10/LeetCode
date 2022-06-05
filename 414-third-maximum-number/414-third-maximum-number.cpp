class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
            return nums[nums.size()-1];
        int cnt = 0;
        for(int i = nums.size()-1;i>0;--i){
            if(nums[i]!=nums[i-1])
                ++cnt;
            if(cnt==3)
                return nums[i];
        }
        if(cnt==2)
            return nums[0];
        return nums[nums.size()-1];
    }
};