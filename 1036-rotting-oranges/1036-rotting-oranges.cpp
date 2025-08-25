class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), dist = 0;
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            dist = q.front().second;
            q.pop();
            int r[4] = {0,1,0,-1};
            int c[4] = {1,0,-1,0};
            for(int i = 0 ; i < 4 ; ++i){
                int newR = r[i]+x;
                int newC = c[i]+y;
                if(newR>=0 && newC>=0 && newR<m && newC<n && grid[newR][newC] == 1){
                    grid[newR][newC] = -1;
                    q.push({{newR, newC}, dist+1});
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1) return -1;
            }
        }
        return dist;
    }
};