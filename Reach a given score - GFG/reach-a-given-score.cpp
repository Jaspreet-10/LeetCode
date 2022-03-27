// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int countScore(long long int index,long long int n,long long int arr[],
map<pair<long long int,long long int>,long long int>&memo){
    if(n==0)
        return 1;
    if(index>2)
        return 0;
    pair<long long int,long long int> currentKey = {index,n};
    if(memo.find(currentKey)!=memo.end())
        return memo[currentKey];
    long long int consider=0;
    if(arr[index]<=n){
        consider = countScore(index,n-arr[index],arr,memo);
    }
    long long int notConsider = countScore(index+1,n,arr,memo);
    memo[currentKey] = notConsider + consider;
    return consider+notConsider;
}
long long int count(long long int n)
{
        long long int arr[3]={3,5,10};
	    map<pair<long long int,long long int>,long long int>memo;
	    return countScore(0,n,arr,memo);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends