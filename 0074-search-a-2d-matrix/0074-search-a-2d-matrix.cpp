class Solution {
public:
    bool findElement(vector<vector<int>>&matrix, int target, int row){
        int low = 0, high = matrix[row].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        for(int i = 0 ; i < matrix.size() ; ++i){
            if(matrix[i][col-1]>=target){
                return findElement(matrix,target,i);
            }
        }
        return false;
    }
};