class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(rooms[i][j] == 0) q.push({{i, j}, 0});
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            int r[4] = {0,1,0,-1};
            int c[4] = {1,0,-1,0};
            for(int i = 0 ; i < 4 ; ++i){
                int newR = r[i]+x;
                int newC = c[i]+y;
                if(newR>=0 && newC>=0 && newR<m && newC<n && rooms[newR][newC] == 2147483647){
                    rooms[newR][newC] = dist+1;
                    q.push({{newR, newC}, dist+1});
                }
            }
        }
        return;
    }
};