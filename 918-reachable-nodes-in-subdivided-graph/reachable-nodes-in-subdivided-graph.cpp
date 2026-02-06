class Solution {
public:
    using ll = long long;
    unordered_map<int, list<pair<int, int>>> adjList;
    const ll INF = 1e18;

    vector<ll> dijkstra(int n, int src) {

        vector<ll> dist(n, INF);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u])
                continue;

            for (auto& p : adjList[u]) {
                int v = p.first;
                int wt = p.second;
                int new_cost = cost + wt;

                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.push({new_cost, v});
                }
            }
        }

        return dist;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

        adjList.clear();

        // build adjList 
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            int w = cnt + 1;

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<ll> dist = dijkstra(n, 0);

        ll ans = 0;

        // original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                ans++;
        }

        // subdivided nodes
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            ll left = 0, right = 0;

            if (dist[u] <= maxMoves)
                left = maxMoves - dist[u];

            if (dist[v] <= maxMoves)
                right = maxMoves - dist[v];

            ans += min((ll)cnt, left + right);
        }

        return (int)ans;
    }
};
