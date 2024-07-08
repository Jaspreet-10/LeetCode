class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int findRow = 0, col = matrix[0].size();
        for(int i = 0 ; i < matrix.size() ; ++i){
            if(matrix[i][col-1]>=target){
                findRow = i;
                break;
            }
        }
        for(int i = 0 ; i < matrix[findRow].size() ; ++i){
            if(matrix[findRow][i] == target) return true;
        }
        return false;
    }
};