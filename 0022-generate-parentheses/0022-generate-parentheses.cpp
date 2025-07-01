class Solution {
public:
    vector<string>helper(int open, int close, int n, string s, vector<string>&str){
        if(open == n && close == open){
            str.push_back(s);
            return str;
        }
        if(open<n)
            helper(open+1, close, n, s+"(", str);
        if(close<open)
            helper(open, close+1, n, s+")", str);
        return str;
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string s = "";
        vector<string>str;
        return helper(open, close, n, s, str);
    }
};