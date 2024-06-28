class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        return codes(s, dp, 0);
    }
    
    int codes(string s, vector<int>& dp, int index) {
        if (index >= s.length()) {
            return 1;
        }
        
        if (dp[index] != -1) {
            return dp[index];
        }
        
        int count = 0;
        
        if (s[index] != '0') {
            count += codes(s, dp, index + 1);
            
            if (index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26) {
                count += codes(s, dp, index + 2);
            }
        }
        
        dp[index] = count;
        return count;
    }
};