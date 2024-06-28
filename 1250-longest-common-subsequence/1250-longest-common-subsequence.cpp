class Solution {
public:
    int lcsLength(int i,int j,string &text1,string &text2,int len1,int len2,vector<vector<int>>&dp){
        if(i>=len1 || j>=len2)
            return 0;
        int ans = -1001;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i] == text2[j]){
            ans = 1+lcsLength(i+1,j+1,text1,text2,len1,len2,dp);
        }else{
            ans=max(lcsLength(i,j+1,text1,text2,len1,len2,dp),lcsLength(i+1,j,text1,text2,len1,len2,dp));
        }
        dp[i][j] =  ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(),len2 = text2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        return lcsLength(0,0,text1,text2,len1,len2,dp);
    }
};