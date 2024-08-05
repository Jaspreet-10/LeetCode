class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int t = k;
        for(int i = 0 ; i < nums.size() ; ++i){
            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            k--;
            if(k == 0){
                ans.push_back(nums[dq.front()]);
                ++k;
            }
            if(!dq.empty() && i - dq.front()+1>=t){
                dq.pop_front();
            }
        }
        return ans;
    }
};