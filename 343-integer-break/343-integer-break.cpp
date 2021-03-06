class Solution {
public:
    int breakInteger(int index,int a[],int n,vector<vector<int>>&dp){
        if(n==0)
            return 1;
        
        if(n<0||index>=n)
            return -1;
        
        if(dp[index][n]!=-1001)
            return dp[index][n];
        
        int consider=0;
        if(n>=a[index]){
            consider = a[index]*breakInteger(index,a,n-a[index],dp);
        }
        int notConsider = breakInteger(index+1,a,n,dp);
        dp[index][n] = max(consider,notConsider);
        return dp[index][n];
    }
    int integerBreak(int n) {
        if(n==2 || n==3) 
            return n-1;
        vector<vector<int>> dp( n+1 , vector<int> (n+1, -1001));
        int a[n];
        for(int i=1;i<=n;++i)
            a[i-1] = i;
        return breakInteger(0,a,n,dp);
    }
};