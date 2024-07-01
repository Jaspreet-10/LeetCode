class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        // int m = 0;
        for(int i = 0 ; i < tokens.size() ; ++i){
            int first = 0, second  = 0;
            string str = tokens[i];
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/"){
            int m = stoi(str);
                s.push(m);
            }else{
                if(!s.empty()){
                first = s.top();
                s.pop();
                }
                if(!s.empty()){
                second = s.top();
                s.pop();
                }
                if(tokens[i] == "+")
                    s.push(first+second);
                if(tokens[i] == "-")
                    s.push(second-first);
                if(tokens[i] == "*")
                    s.push(second*first);
                if(tokens[i] == "/")
                    s.push(second/first);
            }
        }
        return s.top();
    }
};