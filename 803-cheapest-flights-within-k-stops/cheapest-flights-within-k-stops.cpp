class Solution {
public:
    using T = tuple<int, int, int>; // (cost, city, stops)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, list<pair<int,int>>> adjList;
        for (auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];
            adjList[u].push_back({v, w});
        }

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, src, 0);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();

            if (city == dst)
                return cost;

            if (stops > k)
                continue;

            if (dist[city] < stops)
                continue;

            dist[city] = stops;

            for (auto &[v, w] : adjList[city]) {
                int new_cost  = cost + w;
                int new_stops = stops + 1;
                pq.emplace(new_cost, v, new_stops);
            }
        }

        return -1;
    }
};