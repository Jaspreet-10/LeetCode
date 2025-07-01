class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int>v;
        int i = 0, j = 0, maxi = 0;
        while(i<s.size()){
            while(v[s[i]]>0){
                v[s[j]]--;
                ++j;
            }
            v[s[i]]++;
            maxi = max(maxi, i-j+1);
            ++i;
        }
        return maxi;
    }
};