class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int left = 0, max_len = 0, max_count = 0;
        for(int right = 0 ; right < s.size() ; ++right){
            m[s[right]]++;
            max_count = max(max_count,m[s[right]]);
            while(right-left-max_count+1>k){
                m[s[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
        }
        return max_len;
    }
};