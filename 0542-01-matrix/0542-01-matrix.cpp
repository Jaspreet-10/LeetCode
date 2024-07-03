class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>ans = mat;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < mat.size() ; ++i){
            for(int j = 0 ; j < mat[i].size() ; ++j){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            int delRow[4] = {-1,0,+1,0};
            int delCol[4] = {0,+1,0,-1};
            for(int i = 0;i<4;++i){
                int newRow = r+delRow[i];
                int newCol = c+delCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                    if(!vis[newRow][newCol]){
                        ans[newRow][newCol] = steps+1;
                        vis[newRow][newCol] = true;
                        q.push({{newRow,newCol},steps+1});
                    }
                }
            }
        }
        return ans;
    }
};