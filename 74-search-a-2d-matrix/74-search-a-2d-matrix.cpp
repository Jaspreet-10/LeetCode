class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        if(target>=matrix[0][0]){
        for(int i=0;i<=row;++i){
            if(matrix[i][0]==target)
                return true;
            else if(matrix[i][0]>target){
                row=i-1;
                break;
                }
            }
        }
        for(int i=0;i<matrix[row].size();++i){
            if(matrix[row][i]==target)
                return true;
        }
        return false;
    }
};