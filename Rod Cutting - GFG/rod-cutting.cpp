// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int maxProfit(int index,int price[],int n,map<pair<int,int>,int>&memo){
        if(index>=n || n==0)
            return 0;
        pair<int,int>currentKey={index,n};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int consider=0;
        if(index+1<=n)
        consider=price[index]+maxProfit(index,price,n-(index+1),memo);
        int notConsider=maxProfit(index+1,price,n,memo);
        memo[currentKey]=max(consider,notConsider);
        return memo[currentKey];
    }
    int cutRod(int price[], int n) {
        map<pair<int,int>,int>memo;
        return maxProfit(0,price,n,memo);
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