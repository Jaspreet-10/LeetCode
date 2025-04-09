class Solution {
public:
    void helper(string str, int open, int close, int n, vector<string>&ans){
        if(open == close and close == n){
            ans.push_back(str);
            return ;
        }
        if(open<n)
        helper(str+"(", open+1, close, n, ans);
        if(close<open)
        helper(str+")", open, close+1, n, ans);
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string>ans;
        string str = "";
        helper(str, open, close, n, ans);
        return ans;
    }
};