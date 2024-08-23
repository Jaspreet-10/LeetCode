class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count = 0, j = 0, i = 0, ans = 0;
        unordered_map<char,int>m;
        while(i<s.length()){
            m[s[i]]++;
            max_count = max(max_count, m[s[i]]);
            while(j<i && i - j - max_count+1 > k){
                m[s[j]]--;
                max_count = max(max_count, m[s[j]]);
                ++j;
            }
            ans = max(ans, i - j + 1);
            ++i;
        }
        return ans;
    }
};