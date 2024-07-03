class Solution {
public:
    int dfs(int node, vector<bool>&vis,vector<int>adj[]){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
        return 0;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), cnt = 0;
        vector<bool>vis(V,false);
        vector<int>adj[V];
        for(int i = 0 ; i < isConnected.size() ; ++i){
            for(int j = 0 ; j < isConnected[i].size() ; ++j){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0 ; i < V ; ++i){
            if(!vis[i]){
                ++cnt;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};