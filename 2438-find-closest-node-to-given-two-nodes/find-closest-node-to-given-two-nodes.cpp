class Solution {
public:
    void bfs(unordered_map<int, list<int>>& adjList, int start,
             vector<int>& dist, int n) {
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

    void dfs(int node, unordered_map<int, list<int>>& adjList,
             vector<int>& dist, vector<bool>& visited, int currDist) {
        dist[node] = currDist;
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, dist, visited, currDist + 1);
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
        vector<bool> vis1(n, false), vis2(n, false);

        dfs(node1, adjList, dist1, vis1, 0);
        dfs(node2, adjList, dist2, vis2, 0);


        // bfs(adjList, node1, dist1, n);
        // bfs(adjList, node2, dist2, n);

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