class Solution {
public:
    void dijkstra(unordered_map<int, list<int>>& adjList, int start, vector<int>& dist, int n) {
        dist[start] = 0;
        // Min-heap: pair(distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue;

            for (int v : adjList[u]) {
                if (dist[u] + 1 < dist[v]) {  // edge weight = 1
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, list<int>> adjList;

        for (int u = 0; u < n; ++u) {
            if (edges[u] != -1) {
                adjList[u].push_back(edges[u]);
            }
        }

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        dijkstra(adjList, node1, dist1, n);
        dijkstra(adjList, node2, dist2, n);

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
