class Solution {
public:
   vector < int > maxSlidingWindowHelper(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector < int > ans;
        ans = maxSlidingWindowHelper(nums, k);
        return ans;
    }
};


// deque<int>pq;
//         vector<int>ans(nums.size(),0);
//         int left = 0, right = 0;
//         for(int i = 0 ; i < nums.size() ; ++i){
//             while(!pq.empty() and nums[pq.back()]<nums[i]){
//                 pq.pop_back();
//             }
//             pq.push_back(i);
//             while((i-left+1)>=k){
//                 ans[left] = nums[pq.front()];
//                 pq.pop_front();
//                 ++left;
//             }
//         }
//         return ans;