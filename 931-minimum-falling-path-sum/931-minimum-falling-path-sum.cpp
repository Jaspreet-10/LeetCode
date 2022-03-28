class Solution {
public:
//     TC-> O(n * 3^(m*n)) ->For Recursion
//     SC->O(m)
    
    int findMinPaths(int r,int c,int m, int n, vector<vector<int>>&grid,  vector<vector<int>>&memo){
        
        if(r>=m || r<=-1 || c<=-1 || c>=n) 
            return 100001;

        if(r==m-1)
            return grid[r][c];
        
        if(memo[r][c]!=-1)
            return memo[r][c];
        
        int leftDiagonalMove = grid[r][c] + findMinPaths(r+1,c-1,m,n,grid,memo);
        
        int downMove = grid[r][c] + findMinPaths(r+1,c,m,n,grid,memo);
        
        int rightDiagonalMove  = grid[r][c] + findMinPaths(r+1,c+1,m,n,grid,memo);
         
        memo[r][c] = min(leftDiagonalMove,min(rightDiagonalMove,downMove));

        return memo[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int colSize = grid[0].size();
         vector<vector<int>>memo(colSize+1,vector<int>(colSize+1,-1));
        int minimum = 1000000, ans;
        for( int i=0;i<colSize;i++){
         
      ans =  findMinPaths(0,i,colSize,colSize,grid,memo);
              minimum = min(minimum,ans);
         }
        return minimum;
    }
};