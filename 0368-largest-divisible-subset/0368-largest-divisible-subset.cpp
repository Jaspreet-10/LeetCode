class Solution {
public:
    int findSubsets(int index, vector<int>& nums, vector<int>& dp, vector<int>& parent) {
        if (dp[index] != -1) {
            return dp[index]; // Return the stored result if already computed
        }

        int maxLength = 1; // Every element is a subset of itself
        int bestPrevIndex = -1;

        for (int i = 0; i < index; ++i) {
            if (nums[index] % nums[i] == 0) {
                int currentLength = 1 + findSubsets(i, nums, dp, parent);
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    bestPrevIndex = i;
                }
            }
        }

        dp[index] = maxLength;
        parent[index] = bestPrevIndex;
        return maxLength;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end()); // Sort the input array

        vector<int> dp(n, -1); // Memoization table to store the size of the largest subset ending at each index
        vector<int> parent(n, -1); // Array to track the previous element in the largest subset

        int maxIndex = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            if (findSubsets(i, nums, dp, parent) > maxLength) {
                maxLength = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> ans;
        for (int i = maxIndex; i >= 0; i = parent[i]) {
            ans.push_back(nums[i]);
            if (parent[i] == -1) break;
        }

        reverse(ans.begin(), ans.end()); // Reverse to get the subset in the correct order
        return ans;
    }
};