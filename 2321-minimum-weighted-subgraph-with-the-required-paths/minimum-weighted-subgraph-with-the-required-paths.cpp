using ll = long long;
using P =  pair<ll, int>;
class Solution {
public:
    const ll INF = 4e18;
    unordered_map<int, list<pair<int, int>>> adjList;

    vector<ll> dijkstra(int src, int n) {

        vector<ll> dist(n, INF);

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto& [v, wt] : adjList[u]) {

                if (dist[u] + wt < dist[v]) {

                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    ll minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {

        // Original Graph
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adjList[u].push_back({v, wt});
        }

        vector<ll> dist_1 = dijkstra(src1, n);
        vector<ll> dist_2 = dijkstra(src2, n);

        // Reverse Graph
        adjList.clear();

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adjList[v].push_back({u, wt});
        }

        vector<ll> dist_3 = dijkstra(dest, n);

        ll ans = INF;

        for (int i = 0; i < n; i++) {

            if (dist_1[i] == INF || dist_2[i] == INF ||
                dist_3[i] == INF)
                continue;

            ans = min(ans, dist_1[i] + dist_2[i] + dist_3[i]);
        }

        return ans == INF ? -1 : ans;
    }
};