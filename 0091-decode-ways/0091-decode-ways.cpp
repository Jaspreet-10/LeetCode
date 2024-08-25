class Solution {
public:
    int decodeWays(int index, string s,  vector<int>&dp){
        if(index>=s.size()) return 1;
        if(dp[index]!=-1) return dp[index];
        int oneStep = 0, twoStep = 0;
        if(s[index]!='0'){
        oneStep = decodeWays(index+1, s, dp);
        if(index+1 < s.length() && stoi(s.substr(index,2)) <= 26) 
            twoStep = decodeWays(index+2, s, dp);
        }
        return dp[index] = oneStep + twoStep;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return decodeWays(0, s, dp);
    }
};