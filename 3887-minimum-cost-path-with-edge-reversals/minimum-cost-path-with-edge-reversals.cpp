class Solution {
public:
    unordered_map<int, list<pair<int, long long>>> adjList;

    vector<long long> dijkstra(int n) {
        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [node_dist, node] = pq.top();
            pq.pop();

            if (node_dist > dist[node]) 
                continue;

            for (const auto &nbr : adjList[node]) {
                int neighbor = nbr.first;
                long long edge_weight = nbr.second;

                long long new_dist = node_dist + edge_weight;

                if (new_dist < dist[neighbor]) {
                    dist[neighbor] = new_dist;
                    pq.push({new_dist, neighbor});
                }
            }
        }

        return dist;
    }

    long long minCost(int n, vector<vector<int>>& edges) {
        
        adjList.clear();  

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];

            // forward
            adjList[u].push_back({v, w});

            // reverse via switch
            adjList[v].push_back({u, 2 * w});
        }

        vector<long long> dist = dijkstra(n);

        return dist[n - 1] >= 1e18 ? -1 : dist[n - 1];
    }
};