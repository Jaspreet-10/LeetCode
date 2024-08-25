class Solution {
public:
    bool wordBreakHelper(int index, string s, unordered_set<string>&st, vector<int>&dp){
        if(index >= s.size()) return true;
        string str = "";
        if(dp[index]!=-1) return dp[index];
        for(int i = index ; i < s.size() ; ++i){
            str+=s[i];
            if(st.find(str)!=st.end()){
                if(wordBreakHelper(i+1, s, st,dp)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        string str = "";
        vector<int>dp(s.size(),-1);
        return wordBreakHelper(0, s, st,dp);
    }
};