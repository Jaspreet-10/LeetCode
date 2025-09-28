class Solution {
public:
    bool findRowElement(vector<vector<int>>&matrix, int target, int row){
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

     bool findColElement(vector<vector<int>>&matrix, int target, int col){
        int low = 0, high = matrix.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target>=matrix[mid][0] and target<=matrix[mid][col]) 
                return findRowElement(matrix, target, mid);
            else if(matrix[mid][col]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size()-1;
        return findColElement(matrix, target, col);
    }
};