class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<bool>>& ocean, int dir[4][2]){
        if(i < 0 || i >= ocean.size() || j < 0 || j >= ocean[0].size()) return;
        if(matrix[i][j] < prev || ocean[i][j]) return;
        ocean[i][j] = true;
        for(int k = 0; k < 4; k++){
            dfs(matrix, i + dir[k][0], j + dir[k][1], matrix[i][j], ocean, dir);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
       vector<vector<int>> res;
        if(matrix.empty() || matrix[0].empty()) 
            return res;
        
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        
        // Directions array for moving up, down, left, right
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        // DFS for Pacific and Atlantic
        for(int i = 0; i < col; i++){
            dfs(matrix, 0, i, INT_MIN, pacific, dir);
            dfs(matrix, row-1, i, INT_MIN, atlantic, dir);
        }
        for(int i = 0; i < row; i++){
            dfs(matrix, i, 0, INT_MIN, pacific, dir);
            dfs(matrix, i, col-1, INT_MIN, atlantic, dir);
        }
        
        // Preparing the result
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};