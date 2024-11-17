class Solution {
public:
    int countSubstrings(string s) {
         int n = s.size();
        int count = 0;
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        for(int i = 0 ; i < n ; ++i){
            dp[i][i] = true;
            ++count;
        }
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ++count;
            }
        }
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0 ; j< n-i ; ++j){
                if(s[j] == s[i+j] && dp[j+1][j+i-1]){
                    ++count;
                    dp[j][j+i] = true;
                }
            }
        }
        return count;
    }
};