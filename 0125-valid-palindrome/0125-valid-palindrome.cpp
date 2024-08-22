class Solution {
public:
    bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string str = "";
    int c = 0;
    for(int i = 0 ; i < s.length() ; ++i){
        int ch = s[i];
        if((ch>=48&& ch<=57) || (ch>=97 && ch<=122)){
            c = -1;
            str+=s[i];
            }
        }
        cout<<str<<" ";
        if(c == 0)
            return true;
        int i = 0, j = str.length()-1;
        while(i<=j){
            if(str[i]!=str[j])
                return false;
            ++i,--j;
        }
        return true;
    }
};