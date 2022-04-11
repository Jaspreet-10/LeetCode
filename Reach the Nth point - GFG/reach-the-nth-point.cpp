// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    int totalWays(int currentStairs,int targetStairs,unordered_map<int,int>&memo){
        if(currentStairs==targetStairs)
            return 1;
        
        if(currentStairs>targetStairs)
            return 0;
        
        int currentKey=currentStairs;
        
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int oneJump=totalWays(currentStairs+1,targetStairs,memo);
        
        int twoJumps=totalWays(currentStairs+2,targetStairs,memo);
        
        memo[currentKey]=(oneJump+twoJumps)%1000000007;
        
        return memo[currentKey];
    }

		int nthPoint(int n){
            unordered_map<int,int>memo;
            int ans = (totalWays(0,n,memo));
            return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends