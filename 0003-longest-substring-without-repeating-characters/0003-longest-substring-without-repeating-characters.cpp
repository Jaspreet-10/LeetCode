class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxi = 0;
        unordered_map<char, int>m;
        while(right < s.size()){
            m[s[right]]++;
            while(m[s[right]]>1){
                m[s[left]]--;
                ++left;
            }
            maxi = max(maxi, right - left + 1);
            ++right;
        }
        return maxi;
    }
};