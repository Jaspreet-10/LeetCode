// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long int countPath(int row,int col,int m,int n,map<pair<int,int>,long long int>&memo){
      
      if(row==m-1 and col==n-1)
        return 1;
      
      if(row>=m || col>=n){
          return 0;
      }
        pair<int,int>currentKey = {row,col};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        long long int right = countPath(row,col+1,m,n,memo);
        long long int down = countPath(row+1,col,m,n,memo);
        memo[currentKey] = (right+down)%1000000007;
        return memo[currentKey];
  }
    long long int numberOfPaths(int m, int n){
        map<pair<int,int>,long long int>memo;
        return countPath(0,0,m,n,memo);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends