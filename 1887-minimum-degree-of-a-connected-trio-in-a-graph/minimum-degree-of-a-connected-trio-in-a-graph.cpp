class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // adjacency matrix
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        unordered_map<int, int> degree;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u][v] = adj[v][u] = true;
            degree[u]++;
            degree[v]++;
        }

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!adj[i][j])
                    continue;
                for (int k = j + 1; k <= n; k++) {
                    if (adj[i][k] && adj[j][k]) {
                        int trio_degree = degree[i] + degree[j] + degree[k] - 6;
                        ans = min(ans, trio_degree);
                    }
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};