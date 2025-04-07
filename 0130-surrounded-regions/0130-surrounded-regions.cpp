class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>&board){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == 'X' || board[i][j] == '1') return;
        board[i][j] = '1';
        int rowC[4] = {0, -1, 0, 1};
        int colC[4] = {-1, 0, 1, 0};
        for(int k = 0 ; k < 4 ; ++k){
            dfs(rowC[k] + i, colC[k] + j, m, n, board);
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O'){
                    dfs(i,j,m,n,board);
                }
            }
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};