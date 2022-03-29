// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int Jump(int index,int A[],int n){
        if(index == n-1)
            return 1;
        if(index>=n)
            return 0;
        for(int i=1;i<=A[index];++i){
            if(Jump(index+i,A,n))
                return 1;
        }
        return 0;
    }
    int canReach(int A[], int N) {
        // int maxi = *max_element(A,A+n);
        // int dp[N+1][]
        return Jump(0,A,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends