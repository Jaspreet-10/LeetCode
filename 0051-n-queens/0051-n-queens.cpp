class Solution {
public:
     vector<vector<string>>constructAnswer(vector<string>&board, vector<vector<string>>&ans){
       ans.push_back(board); // Directly add the current board configuration as a solution
        return ans;
     }
    bool isSpotValid(int cr, int cc, vector<string>&board, int n){
        int tempRow = cr;
        int tempCol = cc;
        while(tempRow>=0){
            if(board[tempRow][cc] == 'Q') return false;
            tempRow--;
        }
        tempRow = cr;
        while(tempRow>=0 && tempCol>=0){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempRow--;
            tempCol--;
        }
        tempRow = cr;
        tempCol = cc;
         while(tempRow>=0 && tempCol<n){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempRow--;
            tempCol++;
        }
        return true;
    }
    vector<vector<string>>nQueenSolver(int row, int n, vector<string>&board, 
    vector<vector<string>>&ans){
        if(row == n){
            return constructAnswer(board, ans);
        }
        for(int col = 0 ; col < n ; ++col){
            if(isSpotValid(row,col,board,n)){
                board[row][col] = 'Q';
                nQueenSolver(row+1,n,board,ans);
                board[row][col] = '.';
            }
        }
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n); 
        string s(n,'.');
        for(int i = 0 ; i < n ; ++i){
            board[i] = s;
        }
        return nQueenSolver(0,n,board,ans);
    }
};