class Solution {
public:
    void helper(int i, int j, int m, int n, vector<vector<char>>&board,
                vector<vector<int>>&vis){
        if(i<0 || j<0 || j>=n || i>=m || board[i][j]=='X' || vis[i][j]==0) return;
        board[i][j] = 'O';
        vis[i][j] = 0;
        helper(i+1,j,m,n,board,vis);
        helper(i-1,j,m,n,board,vis);
        helper(i,j+1,m,n,board,vis);
        helper(i,j-1,m,n,board,vis);
        return ;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if((i == 0 || j == 0 || j == n-1 || i == m-1) && board[i][j] == 'O'
                and vis[i][j]==-1){
                    helper(i,j,m,n,board,vis);
                }
            }
        }
         for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == 'O' and vis[i][j]==-1){
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};