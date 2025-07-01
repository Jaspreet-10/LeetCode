class Solution {
public:
    vector<string>str;
    vector<string>helper(int open, int close, int n, string &s){
        if(open == n && close == open){
            str.push_back(s);
            return str;
        }
        if(open<n){
            s+="(";
            helper(open+1, close, n, s);
            s.pop_back();
        }
        if(close<open){
            s+=")";
            helper(open, close+1, n, s);
            s.pop_back();
        }
        return str;
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string s = "";
        return helper(open, close, n, s);
    }
};