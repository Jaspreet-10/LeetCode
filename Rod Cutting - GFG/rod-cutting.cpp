// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int maxProfit(int index,int price[],int n,vector<vector<int>>&dp){
        if(index>=n || n==0)
            return 0;
        if(dp[index][n]!=-1)
            return dp[index][n];
        int consider=0;
        if(index+1<=n)
        consider=price[index]+maxProfit(index,price,n-(index+1),dp);
        int notConsider=maxProfit(index+1,price,n,dp);
        dp[index][n]=max(consider,notConsider);
        return dp[index][n];
    }
    int cutRod(int price[], int n) {
        map<pair<int,int>,int>memo;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return maxProfit(0,price,n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends