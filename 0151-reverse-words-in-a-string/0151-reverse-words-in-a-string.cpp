class Solution {
public:
    string reverseWords(string s) {
        int size = s.size()-1;
        string ans = "";
        for(int i = size ; i>=0 ; --i){
            string str = "";
            if(ans.size()>0 && s[i]!=' ') ans+=" ";
            while(i>=0 and s[i]!=' '){
                str+=s[i];
                --i;
            }
            reverse(str.begin(), str.end());
            ans+=str;
        }
        return ans;
    }
};