class Solution {
public:
    void countIslands(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' 
        || grid[i][j] == '.') return ;
        grid[i][j] = '.';
        countIslands(i+1,j,grid);
        countIslands(i,j+1,grid);
        countIslands(i-1,j,grid);
        countIslands(i,j-1,grid);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    countIslands(i,j,grid);
                }
            }
        }
        return cnt;
    }
};