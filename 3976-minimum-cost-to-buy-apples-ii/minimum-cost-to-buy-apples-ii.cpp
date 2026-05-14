using ll = long long;
using P = pair<ll, int>;

class Solution {
public:
    const ll INF = 1e18;

    vector<ll> dijkstra(int src, unordered_map<int, list<pair<int, ll>>>& graph,
                        int n) {

        vector<ll> dist(n, INF);

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {

            auto [curr_dist, node] = pq.top();
            pq.pop();

            if (curr_dist > dist[node]) {
                continue;
            }

            for (auto& [nbr, wt] : graph[node]) {

                if (curr_dist + wt < dist[nbr]) {

                    dist[nbr] = curr_dist + wt;

                    pq.push({dist[nbr], nbr});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices,
                        vector<vector<int>>& roads) {

        unordered_map<int, list<pair<int, ll>>> without_apple;
        unordered_map<int, list<pair<int, ll>>> with_apple;

        // adj list banate hai
        for (auto& r : roads) {

            int u = r[0];
            int v = r[1];

            ll cost = r[2];
            ll taxi = r[3];

            // bina apple ke
            without_apple[u].push_back({v, cost});
            without_apple[v].push_back({u, cost});

            // apple ke sath 
            with_apple[u].push_back({v, cost * taxi});
            with_apple[v].push_back({u, cost * taxi});
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            // shortest empty path from i
            vector<ll> go = dijkstra(i, without_apple, n);

            // shortest with_apple path from i
            vector<ll> back = dijkstra(i, with_apple, n);

            ll best = prices[i];

            // try buying apples from every shop
            for (int j = 0; j < n; j++) {

                if (go[j] == INF || back[j] == INF) {
                    continue;
                }

                ll total = go[j] + prices[j] + back[j];

                best = min(best, total);
            }

            ans[i] = best;
        }

        return ans;
    }
};