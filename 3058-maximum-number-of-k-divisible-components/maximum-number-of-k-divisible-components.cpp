class Solution {
public:
    long long dfs(int u, int parent, unordered_map<int, list<int>>& adjList,
                  vector<int>& values, int k, int& ans) {

        long long sum = values[u];

        for (int v : adjList[u]) {
            if (v != parent) {
                sum += dfs(v, u, adjList, values, k, ans);
            }
        }

        if (sum % k == 0)
            ans++;

        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        unordered_map<int, list<int>> adjList;
        int ans = 0;

        // Build adjacency list
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(0, -1, adjList, values, k, ans);
        return ans;
    }
};
