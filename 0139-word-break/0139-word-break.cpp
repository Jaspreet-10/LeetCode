class Solution {
public:
    bool checkWordBreak(int index, string s, set<string>&st, vector<int>&dp){
        if(index >= s.size()) return true;
        string str = "";
        if(dp[index]!=-1) return dp[index];
        for(int i = index ; i < s.size() ; ++i){
            str+=s[i];
            if(st.find(str)!=st.end()){
                if(checkWordBreak(i+1, s, st, dp)) return true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size(), -1);
        return checkWordBreak(0, s, st, dp);
    }
};