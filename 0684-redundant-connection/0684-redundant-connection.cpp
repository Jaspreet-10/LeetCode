class Solution {
public:
    unordered_map<int, vector<int>> adj;  // Adjacency list
    unordered_map<int, bool> visited;

    bool isConnected(int u, int v) {
        if (u == v) return true;
        visited[u] = true;
        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                if (isConnected(neighbor, v)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            visited.clear();
            int u = edge[0], v = edge[1];
            if (adj.count(u) && adj.count(v)) {
                if (isConnected(u, v)) {
                    return edge;
                }
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {0, 0};  // Shouldn't reach here as per problem constraints
    }
};
