class Solution {
public:
    using P = pair<int, int>; // {distance, node}
    unordered_map<int, list<pair<int, int>>> adjList;

    vector<int> dijkstra(int n, int src) {
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // outdated entry skip
            if (d > dist[u])
                continue;

            // neighbors traverse
            for (auto& [v, w] : adjList[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // graph build
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adjList[u].push_back({v, w});
        }

        // call dijkstra
        vector<int> dist = dijkstra(n, k);

        int maxDist = *max_element(dist.begin() + 1, dist.end());

        return maxDist == INT_MAX ? -1 : maxDist;
    }
};