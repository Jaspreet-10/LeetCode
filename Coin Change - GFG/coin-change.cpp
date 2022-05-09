// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int totalWays(int index,int S[],int m,int n,
                vector<vector<long long int>>&memo){
        if(n==0)
            return 1;
            
        if(index>=m){
            return 0;
        }
        if(memo[index][n]!=-1)
            return memo[index][n];
        long long int consider = 0;
        if(S[index]<=n){
            consider = totalWays(index,S,m,n-S[index],memo);
        }
        long long int notConsider = totalWays(index+1,S,m,n,memo);
        memo[index][n] = consider+notConsider;
        return memo[index][n];
    }
    long long int count(int S[], int m, int n) {
         vector<vector<long long int>>memo(m+1,vector<long long int>(n+1,-1));
        return totalWays(0,S,m,n,memo);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends