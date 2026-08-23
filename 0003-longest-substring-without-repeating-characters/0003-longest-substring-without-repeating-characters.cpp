class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0, maxLen = 0;

        vector<int> v(128, 0);

        while (i < n) {
            v[s[i]]++;

            while (v[s[i]] > 1) {
                v[s[j]]--;
                ++j;
            }

            maxLen = max(maxLen, i - j + 1);

            ++i;
        }

        return maxLen;
    }
};