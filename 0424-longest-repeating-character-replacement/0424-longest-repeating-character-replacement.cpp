class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxCount = 0, ans = 0;
        unordered_map<char,int>m;
        while(i<s.size()){
            m[s[i]]++;
            maxCount = max(maxCount, m[s[i]]);
            while(j<s.size() && i-j-maxCount>=k){
                m[s[j]]--;
                maxCount = max(maxCount, m[s[j]]);
                ++j;
            }
            ans = max(ans, i-j+1);
            ++i;
        }
        return ans;
    }
};