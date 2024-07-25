class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0, j = 0;
        unordered_map<char,int>m;
        for(int i = 0 ; i < s.length() ; ++i){
                while(j<i and m[s[i]]>0){
                    m[s[j]]--;
                    ++j;
                }
            m[s[i]]++;
            answer = max(answer,i-j+1);
        }
        return answer;
    }
};

// Combining these observations:

// The outer loop runs 
// O(n) times.
// The inner while loop runs 
// O(n) times in total over the entire string.
// Therefore, the overall time complexity is 
// O(n).