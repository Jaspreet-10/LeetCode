class Solution {
public:
    bool dfs(vector<vector<char>>&board, string word, int index, int i, 
    int j , int m, int n){
        if(index>=word.size()){
            return true;
        }
        if(i>=m || j>=n || i<0 || j < 0 || board[i][j] == '.' || board[i][j]!=word[index]) 
        return false;
        char temp = board[i][j];
        board[i][j] = '.';
        if(dfs(board,word,index+1,i+1,j,m,n)) return true;
        if(dfs(board,word,index+1,i,j+1,m,n)) return true;
        if(dfs(board,word,index+1,i-1,j,m,n)) return true;
        if(dfs(board,word,index+1,i,j-1,m,n)) return true;
        board[i][j] = temp;
        return false;
    }   
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j, m, n)) return true;
            }
        }
        return false;
    }
};