class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, index1 = 0, index2 = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i = 0 ; i < s.size() ; ++i){
            dp[i][i] = true;
            maxLen = 1;
        }
        for(int i = 0 ; i < n-1 ; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                index1 = i;
                index2 = i+1;
                maxLen = 2;
            }
        }
        for(int start = 2 ; start < n ; ++start){
            for(int end = 0 ; end <= n-start ; ++end){
                if(s[end] == s[start+end] && dp[end+1][end+start-1]){
                    dp[end][end+start] = true;
                    if(((end+start)-end+1)>maxLen){
                        maxLen = (end+start)-end+1;
                        index1 = end;
                        index2 = end+start;
                    }
                }
            }
        }
        string res = "";
        for(int i = index1 ; i <= index2 ; ++i){
            res+=s[i];
        }
        return res;
    }
};