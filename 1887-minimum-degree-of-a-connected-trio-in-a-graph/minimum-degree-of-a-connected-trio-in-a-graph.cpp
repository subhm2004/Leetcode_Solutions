class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {

        unordered_map<int, unordered_set<int>> adjList;  // list -> unordered_set
        unordered_map<int, int> degree;

        // Graph build
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            adjList[u].insert(v);
            adjList[v].insert(u);

            degree[u]++;
            degree[v]++;
        }

        int minDeg = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {

                // O(1) lookup ab — unordered_set ki wajah se
                if (adjList[i].count(j) == 0) continue;

                for (int k = j + 1; k <= n; k++) {

                    // Dono O(1) check
                    if (adjList[i].count(k) && adjList[j].count(k)) {
                        int trioDeg = degree[i] + degree[j] + degree[k] - 6;
                        minDeg = min(minDeg, trioDeg);
                    }
                }
            }
        }

        return minDeg == INT_MAX ? -1 : minDeg;
    }
};