class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int &count){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return count;
        grid[i][j] = 0;
        ++count;
        dfs(i+1, j, m, n, grid, count);
        dfs(i-1, j, m, n, grid, count);
        dfs(i, j+1, m, n, grid, count);
        dfs(i, j-1, m, n, grid, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), area  = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    int count = 0;
                    area = max(area,dfs(i, j, m, n, grid, count));
                }
            }
        }
        return area;
    }
};