class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxi = 0;
        unordered_map<char,int>m;
        while(i<s.size()){
            while(m[s[i]]>0){
                m[s[j]]--;
                ++j;
            }
            m[s[i]]++;
            if(i-j+1 > maxi) maxi = i-j+1;
            ++i;
        }
        return maxi;
    }
};