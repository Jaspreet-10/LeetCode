class Solution {
public:
    bool dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>visPath){
        if(vis[node]!=0) return false;
        vis[node] = 1;
        visPath[node] = 1;
        for(auto it : adj[node]){
            if(vis[it]!=0 and visPath[it]!=0) return true;
            if(dfs(it, adj, vis, visPath)) return true;
            visPath[it] = 0;
        }
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n, 0);
        vector<int>visPath(n, 0);
        vector<int>adj[n];
        for(int i = 0 ; i < pre.size() ; ++i){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 0){
                if(dfs(i, adj, vis, visPath)) return false;
            }
        }
        return true;
    }
};