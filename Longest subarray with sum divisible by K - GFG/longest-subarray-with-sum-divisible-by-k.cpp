// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int nums[], int n, int k)
	{
	   unordered_map<int,int>memo;
        memo[0] = -1;
        int prefixSum = 0, maxi = 0;
        for(int i = 0 ; i < n ; ++i){
            prefixSum+=nums[i];
            int rem = ((prefixSum%k)+k)%k;
            if(memo.find(rem)!=memo.end()){
                maxi = max(maxi,i - memo[rem]);
            }
            else
            memo[rem] = i;
        }
        return maxi;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends