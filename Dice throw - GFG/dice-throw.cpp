// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//   int total = 0;
  long long totalWays(int M,int N,int X,vector<vector<long long>>&dp){
      if(X==0 and N==0)
        return 1;
      if(N==0 || X<=0)
        return 0;
        if(dp[N][X]!=-1)
            return dp[N][X];
        long long ways = 0;
        for(int i = 1 ; i <= M ; ++i){
            long long total  = totalWays(M,N-1,X-i,dp);
            ways+=total;
            dp[N][X] = ways;
        }
        return dp[N][X];
  }
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        return totalWays(M,N,X,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends