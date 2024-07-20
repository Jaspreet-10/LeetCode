class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>m(rowSum.size(),vector<int>(colSum.size(),0));
        int i = 0, j = 0, r = rowSum.size(), n = colSum.size();
        while(i<r && j<n){
            m[i][j] = min(rowSum[i],colSum[j]);
            rowSum[i]-=m[i][j];
            colSum[j]-=m[i][j];
            if(rowSum[i] == 0) ++i;
            if(colSum[j] == 0){
                ++j;
            }
        }
        return m;
    }
};