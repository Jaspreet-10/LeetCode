class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i = 0 ; i < s.length() ; ++i){
            int ch1 = s[i];
            if((ch1>=97 && ch1<=122) || (ch1>=48 && ch1<=57)){
                str+=s[i];
            }
        }
        int i = 0, j = str.length()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            ++i,--j;
        }
        return true;
    }
};