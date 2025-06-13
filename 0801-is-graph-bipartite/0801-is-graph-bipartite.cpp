class Solution {
public:
    bool is_bi(vector<vector<int>> &adj, vector<int> &visited, vector<int> &color, int col, int node) {
        visited[node] = true;
        color[node] = col;
        
        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (!is_bi(adj, visited, color, 1 - col, it))
                    return false;
            } else if (color[it] == col) {
                return false;  // Same color on adjacent nodes
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> visited(n, false);
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!is_bi(graph, visited, color, 0, i))
                    return false;
            }
        }
        return true;
    }
};
