class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>q;
        int m = grid.size(), n = grid[0].size(), steps = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            steps = q.front().second;
            q.pop();
            int row[4] = {-1, 0, 1, 0};
            int col[4] = {0, -1, 0, 1};
            for(int k = 0 ; k < 4 ; ++k){
                int rc = i+row[k];
                int cc = j+col[k];
                if(rc>=0 && cc>=0 && rc<m && cc<n &&
                grid[rc][cc] == 1){
                    grid[rc][cc] = -1;
                    q.push({{rc,cc}, steps+1});
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1) return -1;
            }
        }
        return steps;
    }
};