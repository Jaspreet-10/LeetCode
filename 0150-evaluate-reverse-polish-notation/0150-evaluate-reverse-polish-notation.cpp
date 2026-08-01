class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int first = 0, second = 0;
        for(int i = 0 ; i < tokens.size() ; ++i){
            if(tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-"){
                if(!st.empty()){
                    first = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    second = st.top();
                    st.pop();
                }
                if(tokens[i] == "+"){
                    st.push(first+second);
                }
                if(tokens[i] == "-"){
                    st.push((second-first));
                }
                if(tokens[i] == "/"){
                    if(first!=0)
                    st.push(second/first);
                }
                if(tokens[i] == "*"){
                    st.push(first*second);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};