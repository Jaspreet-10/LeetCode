class Solution {
public:
    void helper(int n, int open, int close, vector<string>&ans, string str){
        if(open == close && close == n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            helper(n,open+1,close,ans,str+"(");
        }
        if(close<open){
            helper(n,open,close+1,ans,str+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        helper(n,0,0,ans,str);
        return ans;
    }
};