class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int V = grid.size(), maxi = INT_MIN, ans = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[i].size() ; ++j){
                if(grid[i][j] == 2){
                    vis[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int>head = q.front();
            q.pop();
            int row[4] = {-1,0,+1,0};
            int col[4] = {0,-1,0,+1};
            for(int i = 0 ; i < 4 ; ++i){
                int newRow = row[i]+head.first.first;
                int newCol = col[i]+head.first.second;
                if(newRow>=0 && newCol>=0 && newRow<grid.size() &&
                newCol < grid[0].size() and grid[newRow][newCol] == 1
                && !vis[newRow][newCol]){
                    ans = head.second+1;
                    vis[newRow][newCol] = true;
                    q.push({{newRow,newCol},head.second+1});
                }
            }
        }
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[i].size() ; ++j){
                if(grid[i][j] == 1 and vis[i][j] == false){
                    return -1;
                }
            }
        }
        return ans;
    }
};