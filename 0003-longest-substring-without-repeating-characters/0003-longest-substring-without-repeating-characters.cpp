class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char,int>m;
        while(i<s.length()){
            while(m[s[i]]>0){
                m[s[j]]--;
                ++j;
            }
            m[s[i]]++;
            ans = max(ans, i-j+1);
            ++i;
        }
        return ans;
    }
};