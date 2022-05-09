// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int amountByMinCoins(int index,int coins[],int M,int V,vector<vector<int>>&dp){
	    if(V==0)
	        return 0;
	    if(index>=M)
	        return 10001;
	     if(dp[index][V]!=-1)
	        return dp[index][V];
	     int consider = 10001;
	     if(coins[index]<=V)
	       consider = 1 + amountByMinCoins(index,coins,M,V-coins[index],dp);
	     int notConsider = amountByMinCoins(index+1,coins,M,V,dp);
	     dp[index][V] = min(consider,notConsider);
	     return dp[index][V];
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans =  amountByMinCoins(0,coins,M,V,dp);
	    if(ans == 10001)
	        return -1;
	       return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends