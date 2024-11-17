class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int &cnt){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return cnt;
        grid[i][j] = 0;
        ++cnt;
        dfs(i+1,j,m,n,grid,cnt);
        dfs(i-1,j,m,n,grid,cnt);
        dfs(i,j+1,m,n,grid,cnt);
        dfs(i,j-1,m,n,grid,cnt);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int r = grid.size(), c = grid[0].size();
        int cnt = 0, maxi = 0;
        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c ; ++j){
                if(grid[i][j] == 1){
                maxi = max(dfs(i,j,r,c,grid,cnt), maxi);
                cnt = 0;
                }
            }
        }
        return maxi;
    }
};