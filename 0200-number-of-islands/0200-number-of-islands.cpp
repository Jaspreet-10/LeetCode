class Solution {
public:
    int dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis, int m, int n){
        if(r>=m || c>=n || c<0 || r<0 || vis[r][c] == -1 || grid[r][c] == '0') return 0;
        vis[r][c] = -1;
        dfs(r+1, c, grid, vis, m, n);
        dfs(r, c+1, grid, vis, m, n);
        dfs(r-1, c, grid, vis, m, n);
        dfs(r, c-1, grid, vis, m, n);
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        // vector<vector<int>>dp(n, vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    ++cnt;
                    dfs(i,j,grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};