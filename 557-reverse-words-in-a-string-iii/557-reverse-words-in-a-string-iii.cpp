class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        string str="",revs="";
        for(int i=0;i<len;++i){
            if(s[i]==' '){
                reverse(str.begin(),str.end());
                revs=revs+str+" ";
                str="";
            }else
            str=str+s[i];
        }
        reverse(str.begin(),str.end());
        revs+=str;
        return revs;
    }
};