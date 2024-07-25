class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, cnt = 0, n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(cnt == 0) ele = nums[i];
            if(nums[i] == ele) ++cnt;
            else --cnt;
        }
        cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(ele == nums[i]) ++cnt;
        }
        if(cnt>(n/2)) return ele;
        return -1;
    }
};