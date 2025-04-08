class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxCount = 0, j = 0;
        unordered_map<char,int>m;
        for(int i = 0 ; i < s.length() ; ++i){
            m[s[i]]++;
            maxCount = max(maxCount, m[s[i]]);
            while(i-j-maxCount+1>k){
                m[s[j]]--;
                maxCount = max(maxCount, m[s[j]]);
                ++j;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};