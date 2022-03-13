class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length()%2!=0) return false;
        for(int i=0;i<s.length();++i){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            if(s[i]==')'){
                if(!st.empty() and st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            if(!st.empty() and s[i]=='}'){
                if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            if(s[i]==']'){
                if(!st.empty() and st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};