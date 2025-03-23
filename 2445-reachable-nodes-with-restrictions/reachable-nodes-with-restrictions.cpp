class Solution {
public:
    int dfs(int node, unordered_map<int, list<int>>& adjList,
            vector<bool>& visited) {
        if (visited[node])
            return 0;

        visited[node] = true;
        int count = 1; // Count this node

        for (int neighbor : adjList[node])
            count += dfs(neighbor, adjList, visited);

        return count;
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        unordered_map<int, list<int>> adjList;
        vector<bool> visited(n, false);

        // Build adjacency list
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int node : restricted)
            visited[node] = true;

        return dfs(0, adjList, visited);
    }
};
