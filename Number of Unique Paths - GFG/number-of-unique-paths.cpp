// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int countPath(int row,int col,int m,int n,map<pair<int,int>,int>&memo){
      
      if(row==m-1 and col==n-1)
        return 1;
      
      if(row>=m || col>=n){
          return 0;
      }
        pair<int,int>currentKey = {row,col};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int right = countPath(row,col+1,m,n,memo);
        int down = countPath(row+1,col,m,n,memo);
        memo[currentKey] = right+down;
        return memo[currentKey];
  }
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        map<pair<int,int>,int>memo;
        return countPath(0,0,m,n,memo);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends