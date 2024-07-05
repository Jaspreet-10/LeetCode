class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i = 0 ; i < s.size() ; ++i){
            dp[i][i] = true;
            ++cnt;
        }
        for(int i = 0 ; i < n-1 ; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ++cnt;
            }
        }
        for(int start = 2 ; start < n ; ++start){
            for(int end = 0 ; end <= n-start ; ++end){
                if(s[end] == s[start+end] && dp[end+1][end+start-1]){
                    dp[end][end+start] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};