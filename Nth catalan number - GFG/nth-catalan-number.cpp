// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findNumber(int n,vector<cpp_int>&dp){
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        cpp_int ways = 0;
        for(int i=0;i<n;++i){
            ways+=findNumber(i,dp)*findNumber(n-i-1,dp);
        }
        dp[n] = ways;
        return ways;
    }
    cpp_int findCatalan(int n) 
    {
        vector<cpp_int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return findNumber(n,dp);
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends