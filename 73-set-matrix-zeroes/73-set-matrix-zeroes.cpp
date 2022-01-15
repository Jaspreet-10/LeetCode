class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        unordered_map<int,int>rt,ct;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(matrix[i][j]==0){
                    rt[i]++;
                    ct[j]++;
                }
            }
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(rt[i]||ct[j])
                    matrix[i][j]=0;
            }
        }
        // return matrix;
    }
};