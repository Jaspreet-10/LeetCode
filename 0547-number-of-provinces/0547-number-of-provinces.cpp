class Solution {
public:
    void dfs(int node, vector<int>adjL[],vector<int>&vis){
        vis[node] = 1;
        for(auto it : adjL[node]){
            if(vis[it] == 0)
            dfs(it,adjL,vis);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), cnt = 0;
        vector<int>vis(n,0);
        vector<int>adjL[n];
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < isConnected[i].size() ; ++j){
                if(isConnected[i][j] == 1){
                    adjL[i].push_back(j);
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(vis[i]==0){
                ++cnt;
                dfs(i,adjL,vis);
            }
        }
        return cnt;
    }
};