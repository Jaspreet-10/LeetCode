// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int maxProfit(int index,int W,int wt[],int val[],int n,
    map<pair<int,int>,int>&memo){
        
        if(index==n)
            return 0;
        
        pair<int,int> currentKey={index,W};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int profitIncluded=0;
        
        if(wt[index]<=W)
        profitIncluded=val[index]+maxProfit(index+1,W-wt[index],wt,val,n,memo);
        
        int profitNotIncluded=maxProfit(index+1,W,wt,val,n,memo);
        
        memo[currentKey]=max(profitIncluded,profitNotIncluded);
        return memo[currentKey];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        map<pair<int,int>,int>memo;
       return maxProfit(0,W,wt,val,n,memo);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends