class Solution {
public:
    int countIsland(int i, int j, int n, int m, vector<vector<int>>&grid, int &count){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] == 0) return count;
        grid[i][j] = 0;
        ++count;
        countIsland(i+1, j, n, m, grid, count);
        countIsland(i-1, j, n, m, grid, count);
        countIsland(i, j+1, n, m, grid, count);
        countIsland(i, j-1, n, m, grid, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0, maxArea = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 1){
                    int count = 0;
                    maxArea = max(maxArea, countIsland(i,j,n,m,grid,count));
                }
            }
        }
        return maxArea;
    }
};