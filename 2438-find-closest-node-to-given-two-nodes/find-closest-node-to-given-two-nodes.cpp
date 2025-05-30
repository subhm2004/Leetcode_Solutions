class Solution {
public:
    void bfs(unordered_map<int, list<int>>& adjList, int start, vector<int>& dist, int n) {
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        dist[start] = 0;
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, list<int>> adjList;

        // Convert edges to adjacency list
        for (int u = 0; u < n; ++u) {
            if (edges[u] != -1) {
                adjList[u].push_back(edges[u]);
            }
        }

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(adjList, node1, dist1, n);
        bfs(adjList, node2, dist2, n);

        int ans = -1, minMaxDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minMaxDist) {
                    minMaxDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};