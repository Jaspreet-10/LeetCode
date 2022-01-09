class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        vector<int>v(256,-1);
        int size=s.length(),maxLen=0,start=-1;
        for(int i=0;i<size;++i){
            if(v[s[i]]>start) start=v[s[i]];
            maxLen=max(maxLen,i-start);
            v[s[i]]=i;
        }
        return maxLen;
    }
};