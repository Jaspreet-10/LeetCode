class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        int row[4] = {0,-1,0,1};
        int col[4] = {1, 0, -1, 0};
        for(int k = 0 ; k < 4 ; ++k){
            int rc = row[k] + i;
            int cc = col[k] + j;
            dfs(rc, cc, m, n, grid);
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == '1'){ 
                    ++count;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        return count;
    }
};