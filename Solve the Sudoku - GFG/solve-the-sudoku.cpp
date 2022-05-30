// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    bool isSubGridValid(int board[][N],int cr,int cc,int n,int i){
        int startRowIndex = (cr/3)*3;
        int startColIndex = (cc/3)*3;
        for(int j = startRowIndex ; j <=startRowIndex+2; ++j){
            for(int k = startColIndex ; k<=startColIndex+2;++k){
                if(board[j][k] == i)
                    return false;
            }
        }
        return true;
    }
    bool isColValid(int board[][N],int cr,int cc,int n,int i){
       for(int j = 0 ; j < n ; ++j){
           if(board[cr][j]==i)
               return false;
       }    
        return true;
    }
    bool isRowValid(int board[][N],int cr,int cc,int n,int i){
       for(int j = 0 ; j < n ; ++j){
           if(board[j][cc]==i)
               return false;
       }    
        return true;
    }
    bool isValid(int board[][N],int cr,int cc,
    int n,int i){
        return isRowValid(board,cr,cc,n,i) and 
               isColValid(board,cr,cc,n,i) and
               isSubGridValid(board,cr,cc,n,i);
    }
    bool sudokuSolver(int board[][N],int cr,int cc,int n){
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
        
        if(board[cr][cc]!=0)
            return sudokuSolver(board,nextRowIndex,nextColIndex,n);
            for(int i = 1 ; i <= 9 ; ++i){
                if(isValid(board,cr,cc,n,i)){
                    board[cr][cc] = i;
                if(sudokuSolver(board,nextRowIndex,nextColIndex,n))
                        return true;
                board[cr][cc] = 0;
                }
            }
        return false;
        }

    //Function to find a solved Sudoku. 
    bool SolveSudoku(int board[N][N])  
    { 
        return sudokuSolver(board,0,0,N);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0 ; i < N ; ++i){
            for(int j = 0 ; j < N ; ++j)
                cout<<grid[i][j]<<" ";
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends