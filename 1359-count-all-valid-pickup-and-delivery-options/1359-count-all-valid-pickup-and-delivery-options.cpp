class Solution {
public:
#define mod 1000000007
#define ll long long

int countOrders(int n) {
    
    vector<ll> dp(n);
    dp[0]=1;
    
    for( int i=1;i<n;i++)
    {
        ll gaps= 2*i+1;
        ll ways= (gaps*gaps)-(gaps*(gaps-1))/2;
        
        dp[i]=(dp[i-1]*ways) % mod;
    }

    return dp[n-1];
}
};
