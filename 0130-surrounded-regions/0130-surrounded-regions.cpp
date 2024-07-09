class Solution {
public:
    int delRow[4] = {-1,0,+1,0};
    int delCol[4] = {0,-1,0,+1};
    void dfs(int row, int col, int m,int n, vector<vector<char>>&board){
        for(int i = 0 ; i < 4 ; ++i){
            int r = row+delRow[i];
            int c = col+delCol[i];
            if(r>=0 && r<m && c>=0 && c<n and board[r][c] == 'O')
            {
                board[r][c] = 'R';
                dfs(r,c,m,n,board);
            }
        }
        return ;
    }
    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; ++i){
            if(board[i][0] == 'O'){
                board[i][0] = 'R';
                dfs(i,0,m,n,board);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            if(board[i][n-1] == 'O'){
                board[i][n-1] = 'R';
                dfs(i,n-1,m,n,board);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(board[0][i] == 'O'){
                board[0][i] = 'R';
                dfs(0,i,m,n,board);
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(board[m-1][i] == 'O'){
                board[m-1][i] = 'R';
                dfs(m-1,i,m,n,board);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'R')
                    board[i][j] = 'O';
            }
        }
        return ;
    }
};