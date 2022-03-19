// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
         int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<string, int>m;
       return maxProfit(W, wt, val, n, 0, m);
    }
private:
    int maxProfit(int capacity, int weights[], int profit[], int n, int CI, unordered_map<string, int>&m){
        if(CI >= n)
            return 0;
        
        string key = to_string(CI) + "-" + to_string(capacity);
        if(m.find(key) != m.end())
            return m[key];
        
        int weightConsider = 0;
        if(capacity >= weights[CI])
            weightConsider = profit[CI] + maxProfit(capacity-weights[CI], weights, profit, n, CI+1, m);
            
        int doNotConsider = maxProfit(capacity, weights, profit, n, CI+1, m);
        
        m[key] = max(weightConsider, doNotConsider);
        return m[key];
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