class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")
            return 0;
        int maxi=0,open=0,close=0,len=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close){
                len=open+close;
                maxi=max(len,maxi);
            }else if(close>open)
                open=close=0;
        }
        open=close=0;
        for(int i=s.length()-1;i>=0;--i){
            if(s[i]==')')
                open++;
            else
                close++;
            if(open==close){
                len=open+close;
                maxi=max(len,maxi);
            }else if(close>open)
                open=close=0;
        }
        return maxi;
    }
};