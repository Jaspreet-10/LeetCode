class Solution {
public:
    string reverseWords(string s) {
        string ans = "",str = "";
        int cnt = 0;
        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == ' ')
                ++cnt;
            else
                break;
        }
        for(int i = s.length()-1;i>=cnt;--i){
            if(s[i]!=' '){
            str+=s[i];
            }
            if(s[i] == ' ' and !str.empty()){
                reverse(str.begin(),str.end());
                ans+=str;
                ans+=s[i];
                str = "";
            }
        }
        reverse(str.begin(),str.end());
        ans+=str;
        return ans;
    }
};