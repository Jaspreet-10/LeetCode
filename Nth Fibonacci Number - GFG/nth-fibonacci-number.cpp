// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        unordered_map<long long int,long long int>map;
        return nthFib(n,map);
    }
    
    
    long long int nthFib(long long int n,unordered_map<long long int,long long int>&map)
    {
         long long int pow=1000000007;
        
        if(n==0)
        return 0;
        
        if(n==1)
        return 1;
        
        
        long long int currentKey=n;
        
        if(map.find(currentKey)!=map.end())
        return map[currentKey];
        
        long long int a=nthFib(n-1,map);
        long long int b=nthFib(n-2,map);
        
        
        map[currentKey]=(a+b)%pow;
        
        return map[currentKey]%pow;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends