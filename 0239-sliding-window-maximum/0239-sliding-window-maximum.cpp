class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int count = k;
        for(int i = 0 ; i < nums.size() ; ++i){
            while(!dq.empty() && nums[dq.front()]<nums[i]){
                dq.pop_front();
            }
            dq.push_front(i);
            --k;
            if(k == 0){
                ans.push_back(nums[dq.back()]);
                ++k;
            }
            if(!dq.empty() && (i-dq.back()+1)>=count){
             dq.pop_back();   
            }
        }
        return ans;
    }
};