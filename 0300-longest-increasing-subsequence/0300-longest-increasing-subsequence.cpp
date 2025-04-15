class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    for (int num : nums) {
        auto it = lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end()) {
            sub.push_back(num); // extend the subsequence
        } else {
            *it = num; // replace to keep subsequence minimal
        }
    }
    return sub.size();
    }
};