class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>m;
        int i = 0, j = 0, maxCount = 0, answer = INT_MIN;
        while(i<s.size()){
            m[s[i]]++;
            maxCount = max(maxCount, m[s[i]]);
            while(j<s.size() && i-j-maxCount+1>k){
                m[s[j]]--;
                maxCount = max(maxCount, m[s[j]]);
                ++j;
            }
            if(answer<i-j+1) answer = i-j+1;
            ++i;
        }
        return answer;
    }
};