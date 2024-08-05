class Solution {
public:
    vector<string>helper(int open, int close, int n, string str, vector<string>&ans){
        if(close == open && close == n){
            ans.push_back(str);
            return ans;
        }
        if(open<n)
            helper(open+1,close,n,str+"(",ans);
        if(close<open)
            helper(open,close+1,n,str+")",ans);
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string>ans;
        return helper(0,0,n,str,ans);
    }
};