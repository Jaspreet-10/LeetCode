class Solution {
public:
    int maximumArea(int Crow,int Ccol,int row,int col,vector<vector<char>>&matrix,
    vector<vector<int>>&dp){
        if(Crow < 0 ||  Crow>=row || Ccol <0 || Ccol>=col || matrix[Crow][Ccol] == '0')
                return 0;
        if(dp[Crow][Ccol]!=-1)
            return dp[Crow][Ccol];
        int right = 1+maximumArea(Crow,Ccol+1,row,col,matrix,dp);
        int down = 1+maximumArea(Crow+1,Ccol,row,col,matrix,dp);
        int diagonal = 1+maximumArea(Crow+1,Ccol+1,row,col,matrix,dp);
        
        dp[Crow][Ccol] = min(right,min(down,diagonal));
        return dp[Crow][Ccol];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int area=0;
       for(int i=0;i<matrix.size();++i){
           for(int j=0;j<matrix[i].size();++j){
               if(matrix[i][j] == '1'){
                int sideLength = maximumArea(i,j,matrix.size(),matrix[0].size(),matrix,dp);
                area = max(area,sideLength*sideLength);
               }
           }
       }
        return area;
    }
};