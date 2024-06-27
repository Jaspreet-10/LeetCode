class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // map<vector<int>,int>m;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; ++i){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    ++left,--right;
                    // m[{nums[i],nums[left],nums[right]}]++;
                    while(left<right and nums[left] == nums[left-1]) ++left;
                    while(left<right and nums[right] == nums[right+1]) --right;
                }
                else if(sum<0){
                ++left;
                }
                else{
                --right;
                }
            }
        }
        return ans;
    }
};