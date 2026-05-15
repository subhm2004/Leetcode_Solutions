class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // adjacency matrix
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        unordered_map<int,int>degree;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u][v] = adj[v][u] = true;
            degree[u]++;
            degree[v]++;
        }

        int minDeg = INT_MAX;

        // Only iterate over edges, then check third node
        // O(E * N) 
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            for (int k = 1; k <= n; k++) {
                if (adj[u][k] && adj[v][k]) {
                    // Valid trio (u, v, k) found
                    // -6 because each internal edge is counted twice in degrees
                    int trioDeg = degree[u] + degree[v] + degree[k] - 6;
                    minDeg = min(minDeg, trioDeg);
                }
            }
        }

        return minDeg == INT_MAX ? -1 : minDeg;
    }
};