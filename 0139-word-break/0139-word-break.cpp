class Solution {
public:
    bool helper(int index, string s, set<string>&st, vector<int>&dp){
        if(index>=s.size()) return true;
        string str = "";
        if(dp[index]!=-1) return dp[index];
        for(int i = index ; i < s.size() ; ++i){
            str+=s[i];
            if(st.find(str)!=st.end()){
                if(helper(i+1, s, st, dp)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(), -1);
        set<string>st(wordDict.begin(), wordDict.end());
        return helper(0, s, st, dp);
    }
};