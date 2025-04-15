class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        for(int i = 0 ; i < n ; ++i){
            dp[i][i] = true;
            maxLen = 1;
        }
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0; j < n-i ; ++j){
                if(s[j] == s[i+j] && dp[j+1][j+i-1]){
                    dp[j][j+i] = true;
                    start = j;
                    maxLen = i+1;
                }
            }
        }
        return (maxLen >= 1) ? s.substr(start, maxLen) : "";
    }
};