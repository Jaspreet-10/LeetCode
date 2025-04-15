class Solution {
public:
    int checkLCS(int i, int j, int m, int n, string &text1, string &text2, 
    vector<vector<int>>&dp){
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int consider = 0, notConsider = 0;
        if(text1[i] == text2[j]){
           consider = 1+checkLCS(i+1, j+1, m, n, text1, text2, dp);
        }else{
            notConsider = max(checkLCS(i, j+1, m, n, text1, text2, dp), 
                            checkLCS(i+1, j, m, n, text1, text2, dp));
        }
        return dp[i][j] = max(consider, notConsider);

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return checkLCS(0, 0, m, n, text1, text2, dp);
    }
};