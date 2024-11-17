class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long start = 1, end = 1, maxi = INT_MIN;
        int i = 0, j = nums.size()-1;
        while(i<nums.size() && j>=0){
            start*=nums[i];
            end*=nums[j];
            maxi = max(max(start,end), maxi);
            if(start == 0) start = 1;
            if(end == 0) end = 1;
            ++i, --j;
        }
        return maxi;
    }
};