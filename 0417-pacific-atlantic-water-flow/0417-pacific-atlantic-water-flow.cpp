class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> at(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, 0, p, heights);
            dfs(i, m - 1, at, heights);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, p, heights);
            dfs(n - 1, i, at, heights);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] == 1 && at[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    vector<int>naa={-1,0,1,0};
    vector<int>nbb={0,-1,0,1};
    void dfs(int a, int b, vector<vector<int>>& oc,
             vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        oc[a][b] = 1;
        for (int i = 0; i < 4; i++) {
            int na = naa[i] + a;
            int nb = nbb[i] + b;
            if (na >= 0 && na < n && nb >= 0 && nb < m && !oc[na][nb] &&
                heights[na][nb] >= heights[a][b]) {
                
                dfs(na, nb, oc, heights);
            }
        }
    }
};