class Solution {
public:
    int lh = 0, rh = 0;
    int totalWays(int i, int n, vector<int>&vis){
        if(i>n){
            return 0; 
        }
        if(i == n){
            return 1;
        }
        if(vis[i]!=-1)
            return vis[i];
         lh=totalWays(i+1,n,vis);
         rh=totalWays(i+2,n,vis);
         vis[i] = lh+rh;
         return vis[i];
    }
    int climbStairs(int n) {
        int ans = 0;
        vector<int>vis(n,-1);
            int count = 0;
            ans+=totalWays(0,n,vis);
        return ans;
    }
};