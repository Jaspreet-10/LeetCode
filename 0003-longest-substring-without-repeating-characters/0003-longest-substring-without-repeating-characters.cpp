class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int j = 0, i = 0, maxi = 0;
        while(i<s.length()){
            m[s[i]]++;
            while(j<i && m[s[i]]>1){
                m[s[j]]--;
                ++j;
            }
            maxi = max(maxi, i-j+1);
            ++i;
        }
        return maxi;
    }
};