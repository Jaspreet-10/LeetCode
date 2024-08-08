class Solution {
public:
    void countIslands(int row, int column, vector<vector<char>>&grid, vector<vector<int>>&vis, 
    int numberOfRowsInTheGrid, int numberOfColumnInTheGrid){
        if(row<0 || column<0 || row>=numberOfRowsInTheGrid || 
        column>=numberOfColumnInTheGrid || grid[row][column] == '0' || vis[row][column] == -1)
            return ;
        vis[row][column] = -1;
        countIslands(row-1,column,grid,vis,numberOfRowsInTheGrid,numberOfColumnInTheGrid);
        countIslands(row+1,column,grid,vis,numberOfRowsInTheGrid,numberOfColumnInTheGrid);
        countIslands(row,column-1,grid,vis,numberOfRowsInTheGrid,numberOfColumnInTheGrid);
        countIslands(row,column+1,grid,vis,numberOfRowsInTheGrid,numberOfColumnInTheGrid);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int numberOfRowsInTheGrid = grid.size(),
        numberOfColumnsInTheGrid = grid[0].size(); 
        int counter = 0;
        vector<vector<int>>vis(numberOfRowsInTheGrid,vector<int>(numberOfColumnsInTheGrid,0));
        for(int i = 0 ; i < numberOfRowsInTheGrid ; ++i){
            for(int j = 0 ; j < numberOfColumnsInTheGrid ; ++j){
                if(grid[i][j] == '1' && vis[i][j]!=-1){
                    counter+=1;
                    countIslands(i,j,grid,vis, numberOfRowsInTheGrid, numberOfColumnsInTheGrid);
                }
            }
        }
         return counter;
    }
};