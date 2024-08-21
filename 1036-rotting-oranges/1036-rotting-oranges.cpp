class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        int m = grid.size(), n = grid[0].size();
        int countOranges = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 2){
                     grid[i][j] = -1;
                     q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            countOranges = q.front().second;
            q.pop();
            int r[4] = {-1, 0, 1, 0};
            int c[4] = {0, -1, 0, 1};
            for(int i = 0 ; i < 4 ; ++i){
                int newRow = r[i]+row;
                int newCol = c[i]+col;
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && 
                grid[newRow][newCol] == 1){
                     grid[newRow][newCol] = -1;
                    q.push({{newRow,newCol},countOranges+1});
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1) return -1;
            }
        }
        return countOranges;
    }
};