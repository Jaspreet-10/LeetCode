class Solution {
public:
    void helper(int n, vector<string>&ans, int open, int close, string str){
        if(open == close && close == n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            helper(n, ans, open+1,close,str+"(");
        }
        if(close<open){
            helper(n, ans, open,close+1,str+")");
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = 0, close = 0;
        string str = "";
        helper(n, ans, open, close, str);
        return ans;
    }
};