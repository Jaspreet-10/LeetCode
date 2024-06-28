class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>mapRow, mapCol;
        for(int i = 0 ; i < matrix.size() ; ++i){
            for(int j = 0 ; j < matrix[i].size() ; ++j){
                if(matrix[i][j] == 0){
                    mapRow[i]++;
                    mapCol[j]++;
                } 
            }
        }
        for(int i = 0 ; i < matrix.size() ; ++i){
            for(int j = 0 ; j < matrix[i].size() ; ++j){
                if(mapRow[i]>0 || mapCol[j]>0){
                    matrix[i][j] = 0;
                } 
            }
        }
        return;
    }
};