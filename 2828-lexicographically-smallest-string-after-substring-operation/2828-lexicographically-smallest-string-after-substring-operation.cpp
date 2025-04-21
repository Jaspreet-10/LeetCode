class Solution {
public:
    string smallestString(string s) {
        bool flag = true;
        for(int i = 0 ; i < s.size() ; ++i){
            int ch = s[i]-'a';
            if(ch>0){
                s[i] = 'a' + (ch - 1);
                flag = false;
            }
            else if(flag == false) break;
        }
        if(flag)
        s[s.size()-1] = 'z';
        return s;
    }
};