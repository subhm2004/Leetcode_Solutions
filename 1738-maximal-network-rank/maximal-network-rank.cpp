class Solution {
public:
    void countDegrees(const vector<vector<int>>& roads, vector<int>& degree,
                      vector<vector<bool>>& connected) {
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = connected[v][u] = true;
        }
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        // Count degrees
        countDegrees(roads, degree, connected);

        int maxRank = 0;

        // Compute maximal network rank
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j] - connected[i][j]; // Subtract if directly connected
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
