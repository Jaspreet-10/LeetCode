class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int answer = 0, j = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            if(m[s[i]]>0){
                while(j<s.size() and m[s[i]]>0){
                    m[s[j]]--;
                    ++j;
                }
            }
            m[s[i]]++;
            answer = max(answer,i-j+1);
        }
        return answer;
    }
};