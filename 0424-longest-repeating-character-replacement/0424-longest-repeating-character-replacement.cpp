class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxi = 0, max_count = 0;
        unordered_map<char,int>m;
        while(i<s.length()){
            m[s[i]]++;
            max_count = max(max_count, m[s[i]]);
            while(i - j - max_count+1 > k){
                m[s[j]]--;
                ++j;
            }
            maxi = max(maxi, i-j+1);
            ++i;
        }
        return maxi;
    }
};