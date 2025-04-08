class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = 0, outlier = INT_MIN;
        unordered_map<int,int>m;
        for(auto it : nums){
            totalSum+=it;
            m[it]++;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if((totalSum-nums[i])%2 != 0) continue;
            int requiredSum = (totalSum-nums[i])/2;
            m[nums[i]]--;
            if(m[requiredSum] > 0){
                outlier = max(outlier, nums[i]);
            }
            m[nums[i]]++; 
        }
        return outlier;
    }
};