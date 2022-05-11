// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int calArea(vector<vector<int>>&mat,int r,int c,int n,int m,
                vector<vector<int>>&dp){
        if(r>=n || c>=m || r<0 || c<0 || mat[r][c]==0)
                return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int right = 1 + calArea(mat,r+1,c,n,m,dp);
        int down = 1 + calArea(mat,r,c+1,n,m,dp);
        int rightDiagonal = 1 + calArea(mat,r+1,c+1,n,m,dp);
        dp[r][c] = min(right,min(down,rightDiagonal));
        return dp[r][c];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int area = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i = 0 ; i < mat.size() ; ++i){
            for(int j = 0 ; j < mat[i].size();++j){
                if(mat[i][j]==1){
                    area = max(area,calArea(mat,i,j,n,m,dp));
                }
            }
        }
        return area;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends