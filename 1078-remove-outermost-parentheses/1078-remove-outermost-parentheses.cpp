class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        bool flag = false;
        string str = "";
        for(int i = 0 ; i < s.size() ; ++i){
            if(!flag){ 
                flag = true;
                continue;
            }
            if(s[i] == '('){
                str+="(";
                st.push('(');
            }
            else{
                if(!st.empty() and st.top() == '('){
                    str+=")";
                    st.pop();
                }else{
                    flag = false;
                }
            }
        }
        return str;
    }
};