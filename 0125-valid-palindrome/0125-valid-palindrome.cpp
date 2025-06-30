class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(),::tolower);
        string str = "";
        for(int i = 0 ; i < s.size() ; ++i){
            if((s[i]-'0'>=0 and s[i]-'0'<=9) || (s[i]-'a'>=0 and s[i]-'a'<=25)){
                str+=s[i];
            }else continue;
        }
        int i = 0, j = str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            ++i, --j;
        }
        return true;
    }
};