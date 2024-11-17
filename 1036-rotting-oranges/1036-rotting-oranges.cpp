class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,pair<int,int>>>&q, int&time){
        int m = grid.size(), n = grid[0].size();
        while(!q.empty()){
            time = q.front().first;
            pair<int,int>p = q.front().second;
            q.pop();
            int row = p.first, col = p.second;
             int r[4] = {-1, 0, 1, 0};
            int c[4] = {0, -1, 0, 1};
           for(int i = 0 ; i < 4 ; ++i){
                int newRow = r[i]+row;
                int newCol = c[i]+col;
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && 
                grid[newRow][newCol] == 1){
                     grid[newRow][newCol] = -1;
                    q.push({time+1, {newRow,newCol}});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int time = 0;
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(),-1));
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[i].size() ; ++j){
                if(grid[i][j] == 2){
                    grid[i][j] = -1;
                    q.push({0,{i,j}});
                }
            }
        }
       time = bfs(grid,q,time);
       for(int i = 0 ; i < grid.size() ; ++i){
        for(int j = 0 ; j < grid[i].size() ; ++j){
            if(grid[i][j] == 1) return -1;
        }
       }
        return time;
    }
};