class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {

        unordered_map<int, list<pair<int, long long>>> adjList;
        
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];
            
            // Forward edge: u -> v with cost w
            adjList[u].push_back({v, w});
            
            // Reverse edge (using switch): v -> u with cost 2*w
            adjList[v].push_back({u, 2 * w});
        }
        
        // Dijkstra's algorithm
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip if we've already found a better path
            if (d > dist[u]) continue;
            
            // Explore all neighbors
            for (auto [v, w] : adjList[u]) {
                long long new_dist = dist[u] + w;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }
        
        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};