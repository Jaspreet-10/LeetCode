class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, maxLen = 0;
        unordered_map<char, int>m;
        while(i<n){
            m[s[i]]++;
            while(j<n && m[s[i]]>1){
                m[s[j]]--;
                ++j;
            }
            if(i-j+1>=maxLen){
                maxLen = i-j+1;
            }
            ++i;
        }
        return maxLen;
    }
};