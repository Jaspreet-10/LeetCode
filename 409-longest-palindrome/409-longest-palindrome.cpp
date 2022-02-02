class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==1)
            return 1;
        map<char,int>m;
        int count=0;
        for(int i=0;i<s.length();++i){
            if(m[s[i]]==0)
            m[s[i]]++;
            else{
                count+=m[s[i]]+1;
                m[s[i]]=0;
            }
        }
        if(count==s.length())
            return count;
        return count+1;
    }
};