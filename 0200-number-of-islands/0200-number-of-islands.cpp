class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int cnt = 0;
        // vector<vector<int>>vis(r, vector<int>(c,-1));
        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c ; ++j){
                if(grid[i][j] == '1'){
                ++cnt;
                dfs(i,j,r,c,grid);
                }
            }
        }
        return cnt;
    }
};