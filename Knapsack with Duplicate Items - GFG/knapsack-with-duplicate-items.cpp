// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxProfit(int wt[],int val[],int W,int index,int N,int dp[][1001]){
        if(W==0)
            return 0;
        
        if(index>=N)
            return 0;
        
        if(dp[index][W]>-1)
            return dp[index][W];
        int consider=0;
        if(wt[index]<=W)
        consider=val[index]+maxProfit(wt,val,W-wt[index],index,N,dp);
        int notConsider=maxProfit(wt,val,W,index+1,N,dp);
        dp[index][W]=max(consider,notConsider);
        return dp[index][W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return maxProfit(wt,val,W,0,N,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends