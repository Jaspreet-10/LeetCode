class Solution {
public:
    vector<string>str;
    vector<string>helper(int open, int close, int n, string s){
        if(open == n && close == open){
            str.push_back(s);
            return str;
        }
        if(open<n)
            helper(open+1, close, n, s+"(");
        if(close<open)
            helper(open, close+1, n, s+")");
        return str;
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string s = "";
        return helper(open, close, n, s);
    }
};