class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        if(t.length()<s.length()) return false;
        for(int i=0;i<t.length();++i){
            if(j<=i and s[j]==t[i]){
                j++;
            }
        }
        if(s.length()==j)
            return true;
        return false;
    }
};