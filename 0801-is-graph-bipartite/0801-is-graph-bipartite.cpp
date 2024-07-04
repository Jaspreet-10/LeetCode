class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<vector<int>>&adjL,int flag, 
    vector<int>&check){
        vis[node] = 1;
        check[node] = flag;
        for(auto it:adjL[node]){
            if(vis[it] == 0){
                if(!dfs(it, vis, adjL, !flag, check)) return false;
            }if(check[it] == flag) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>adjL[N];
        vector<int>vis(N,0);
        vector<int>check(N,0);
        int flag = 0;
        for(int i = 0 ; i < N ; ++i){
            if(vis[i] == 0){
                if(!dfs(i, vis, graph, flag, check)) return false;
            }
        }
        return true;
    }
};