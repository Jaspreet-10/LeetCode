class Solution {
public:
    int countIslands(int i, int j, vector<vector<int>>& grid, int& cnt){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 
        || grid[i][j] == -1) return 0;
        grid[i][j] = -1;
        ++cnt;
        countIslands(i+1,j,grid,cnt);
        countIslands(i,j+1,grid,cnt);
        countIslands(i-1,j,grid,cnt);
        countIslands(i,j-1,grid,cnt);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int cnt = 0,ans = 0;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    countIslands(i,j,grid,cnt);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};