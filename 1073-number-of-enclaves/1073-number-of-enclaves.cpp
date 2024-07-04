class Solution {
public:
    int delRow[4] = {-1,0,+1,0};
    int delCol[4] = {0,-1,0,+1};
    void dfs(int row, int col, int m,int n, vector<vector<int>>&board){
        for(int i = 0 ; i < 4 ; ++i){
            int r = row+delRow[i];
            int c = col+delCol[i];
            if(r>=0 && r<m && c>=0 && c<n and board[r][c] == 1)
            {
                board[r][c] = -1;
                dfs(r,c,m,n,board);
            }
        }
        return ;
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(),cnt = 0;
        for(int i = 0 ; i < m ; ++i){
            if(board[i][0] == 1){
                board[i][0] = -1;
                dfs(i,0,m,n,board);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            if(board[i][n-1] == 1){
                board[i][n-1] = -1;
                dfs(i,n-1,m,n,board);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(board[0][i] == 1){
                board[0][i] = -1;
                dfs(0,i,m,n,board);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(board[m-1][i] == 1){
                board[m-1][i] = -1;
                dfs(m-1,i,m,n,board);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == 1)
                   ++cnt;
            }
        }
        return cnt;
    }
};