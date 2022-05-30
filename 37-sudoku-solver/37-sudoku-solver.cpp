class Solution {
public:
    bool isSubGridValid(vector<vector<char>>&board,int cr,int cc,
                    int n,int i){
        char ch = i+'0';
        int startRowIndex = (cr/3)*3;
        int startColIndex = (cc/3)*3;
        for(int j = startRowIndex ; j <=startRowIndex+2; ++j){
            for(int k = startColIndex ; k<=startColIndex+2;++k){
                if(board[j][k] == ch)
                    return false;
            }
        }
        return true;
    }
    bool isColValid(vector<vector<char>>&board,int cr,int cc,
                    int n,int i){
        char ch = i+'0';
       for(int j = 0 ; j < n ; ++j){
           if(board[cr][j]==ch)
               return false;
       }    
        return true;
    }
    bool isRowValid(vector<vector<char>>&board,int cr,int cc,
                    int n,int i){
        char ch = i+'0';
       for(int j = 0 ; j < n ; ++j){
           if(board[j][cc]==ch)
               return false;
       }    
        return true;
    }
    bool isValid(vector<vector<char>>&board,int cr,int cc,
    int n,int i){
        return isRowValid(board,cr,cc,n,i) and 
               isColValid(board,cr,cc,n,i) and
               isSubGridValid(board,cr,cc,n,i);
    }
    bool sudokuSolver(vector<vector<char>>&board,int cr,int cc,
    int n){
        if(cr == n)
          return true;
        int nextRowIndex = 0;
        int nextColIndex = 0;
        if(cc != n-1){
           nextRowIndex = cr;
           nextColIndex = cc+1; 
        }else{
            nextRowIndex = cr+1;
            nextColIndex = 0;
        }
        
        if(board[cr][cc]!='.')
            return sudokuSolver(board,nextRowIndex,nextColIndex,
                                n);
            for(int i = 1 ; i <= 9 ; ++i){
                if(isValid(board,cr,cc,n,i)){
                    char ch = i+'0';
                    board[cr][cc] = ch;
                if(sudokuSolver(board,nextRowIndex,nextColIndex,n))
                        return true;
                board[cr][cc] = '.';
                }
            }
        return false;
        }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0,board.size());
    }
};