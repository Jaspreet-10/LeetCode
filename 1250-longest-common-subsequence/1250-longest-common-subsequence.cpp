class Solution {
public:
    int lcs(int i, int j, int n, int m, string &text1, string &text2, 
    map<pair<int,int>,int>&M){
        if(i>=n || j>=m) return 0;
        pair<int,int>p = {i,j};
        if(M.find(p)!=M.end()) return M[p];

        int consider = 0, notConsider = 0;
        if(text1[i] == text2[j]) 
        consider = 1 + lcs(i+1, j+1, n, m, text1, text2, M);
        else{
            notConsider = max(lcs(i+1, j, n, m, text1, text2, M),
            lcs(i, j+1, n, m, text1, text2, M));
        }
       return M[p] = max(consider,notConsider);
    }
    int longestCommonSubsequence(string text1, string text2) {
        map<pair<int,int>,int>m;
        return lcs(0, 0, text1.length(), text2.length(), text1, text2, m);
    }
};