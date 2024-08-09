class Solution {
public:
    bool helper(int index, string s, unordered_set<string>&st,vector<int>&dp){
        if(index == s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        string temp="";
        for(int i = index ; i < s.size() ; ++i){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(helper(i+1,s,st,dp)) return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return helper(0,s,st,dp);
    }
};