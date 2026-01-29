// typedef long long ll;  // Dijkstra Algorithm TLE 571 / 581
// class Solution {
// public:
//     unordered_map<int, list<pair<int, int>>> adjList;

//     ll dijkstra_algo(int start, int end) {
//         vector<ll> dist(26, LLONG_MAX);
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

//         dist[start] = 0;
//         pq.emplace(0, start);

//         while (!pq.empty()) {
//             auto [cost, node] = pq.top();
//             pq.pop();

//             if (node == end)
//                 return cost;

//             if (cost > dist[node])
//                 continue;

//             for (auto [nbr, edge_cost] : adjList[node]) {
//                 if (cost + edge_cost < dist[nbr]) {
//                     dist[nbr] = cost + edge_cost;
//                     pq.emplace(dist[nbr], nbr);
//                 }
//             }
//         }

//         return LLONG_MAX;
//     }

//     ll minimumCost(string source, string target, vector<char>& original,
//                    vector<char>& changed, vector<int>& cost) {

//         adjList.clear();
//         ll ans = 0;

//         for (int i = 0; i < cost.size(); ++i) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             adjList[u].push_back({v, cost[i]});
//         }

//         for (int i = 0; i < source.length(); ++i) {
//             if (source[i] == target[i])
//                 continue;

//             int start = source[i] - 'a';
//             int end = target[i] - 'a';

//             ll min_cost = dijkstra_algo(start, end);
//             if (min_cost == LLONG_MAX)
//                 return -1;

//             ans += min_cost;
//         }

//         return ans;
//     }
// };

// Floyd–Warshall

typedef long long ll;

class Solution {
public:
    ll minimumCost(string source, string target, vector<char>& original,
                   vector<char>& changed, vector<int>& cost) {

        const ll INF = 1e18;
        vector<vector<ll>> dist(26, vector<ll>(26, INF));

        // same character ki conversion cost = 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // direct conversions karte hai
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }

        // Floyd–Warshall: all-pairs shortest path
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // answer nikalte hai
        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (dist[s][t] == INF)
                return -1;
            ans += dist[s][t];
        }

        return ans;
    }
};