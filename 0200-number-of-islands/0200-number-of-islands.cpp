class Solution {
public:
    void countIsland(int i, int j, int n, int m, vector<vector<char>>&grid){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] == '0') return ;
        grid[i][j] = '0';
        countIsland(i+1, j, n, m, grid);
        countIsland(i-1, j, n, m, grid);
        countIsland(i, j+1, n, m, grid);
        countIsland(i, j-1, n, m, grid);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == '1'){
                    ++count;
                    countIsland(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
};