class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        if(n<4)
            return res;
        for(int i = 0 ; i < n-3 ; ++i){
            for(int j = i+1 ; j < n-2 ; ++j){
                int k = j+1, right = n-1;
                long long diff = (long long) target - nums[j] - nums[i];
               while(k<right){
                    int sum = nums[k]+nums[right];
                    if(sum == diff){
                        int a = nums[k],b = nums[right];
                        res.push_back({nums[i],nums[j],nums[k],nums[right]});
                        ++k;
                        --right;
                        while(k<right && nums[k] == a) ++k;
                        while(k<right && nums[right] == b) --right;
                    }else if(sum>diff)
                        --right;
                      else
                        ++k;
                }while(j<n-1 && nums[j] == nums[j+1]) ++j;
            }while(i<n-1 && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};