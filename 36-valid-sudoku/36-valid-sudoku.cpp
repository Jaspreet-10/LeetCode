class Solution {
public:
    bool isSubGridValid(vector<vector<char>>&board,int cr,int cc,int n,char ch){
        int startRowIndex = (cr/3)*3;
        int startColIndex = (cc/3)*3;
        for(int j = startRowIndex ; j <=startRowIndex+2; ++j){
            for(int k = startColIndex ; k<=startColIndex+2;++k){
                if(board[j][k] == ch and cr!=j and cc!=k){
                    cout<<"dia\n";
                    return false;
                }
            }
        }
        return true;
    }
    bool isColValid(vector<vector<char>>&board,int cr,int cc,int n,char ch){
       for(int j = cc ; j < n ; ++j){
           if(board[cr][j]==ch and j!=cc){
               cout<<"col\n";
               return false;
           }
       }    
        return true;
    }
    bool isRowValid(vector<vector<char>>&board,int cr,int cc,int n,char ch){
       for(int j = cr ; j < n ; ++j){
           if(board[j][cc]==ch and j!=cr){
               cout<<board[j][cc]<<"row\n";
               return false;
           }
       }    
        return true;
    }
    bool isValid(vector<vector<char>>&board,int cr,int cc,int n,char ch){
        return isRowValid(board,cr,cc,n,ch) and 
               isColValid(board,cr,cc,n,ch) and
               isSubGridValid(board,cr,cc,n,ch);
    }
    bool sudokuSolver(vector<vector<char>>&board,int cr,int cc,int n){
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j]!='.')
                if(isValid(board,i,j,n,board[i][j])==false)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         return sudokuSolver(board,0,0,board.size());
    }
};