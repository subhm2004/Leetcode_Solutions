typedef long long ll;

class Solution {
public:
    unordered_map<int, list<pair<int, ll>>> adjList;
    ll dp[26][26];

    ll dijkstra_algo(int start, int end) {

        if (dp[start][end] != -1)
            return dp[start][end];

        vector<ll> dist(26, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            auto [curr_cost, node] = pq.top();
            pq.pop();

            if (curr_cost > dist[node])
                continue;

            if (node == end) {
                return dp[start][end] = curr_cost;
            }

            for (auto& nbr : adjList[node]) {
                int nbr_node = nbr.first;
                ll wt = nbr.second;

                ll new_cost = curr_cost + wt;

                if (new_cost < dist[nbr_node]) {
                    dist[nbr_node] = new_cost;
                    pq.push({new_cost, nbr_node});
                }
            }
        }

        return dp[start][end] = LLONG_MAX;
    }

    ll minimumCost(string source, string target, vector<char>& original,
                   vector<char>& changed, vector<int>& cost) {

        adjList.clear();
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            ll w = cost[i];

            adjList[u].push_back({v, w});
        }

        ll ans = 0;

        for (int i = 0; i < source.size(); i++) {

            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (s == t)
                continue;

            ll min_cost = dijkstra_algo(s, t);

            if (min_cost == LLONG_MAX)
                return -1;

            ans += min_cost;
        }

        return ans;
    }
};

// // Floyd–Warshall

// typedef long long ll;
// class Solution {
// public:
//     ll minimumCost(string source, string target, vector<char>& original,
//                    vector<char>& changed, vector<int>& cost) {

//         const ll INF = 1e18;
//         vector<vector<ll>> dist(26, vector<ll>(26, INF));

//         // same character ki conversion cost = 0
//         for (int i = 0; i < 26; i++) {
//             dist[i][i] = 0;
//         }

//         // direct conversions karte hai
//         for (int i = 0; i < original.size(); i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             dist[u][v] = min(dist[u][v], (ll)cost[i]);
//         }

//         // Floyd–Warshall: all-pairs shortest path (har character se har
//         character tak ka shortest path or cost )
//         // kya main i → j k ke through sasta bana sakta hoon?
//         for (int k = 0; k < 26; k++) {
//             for (int i = 0; i < 26; i++) {
//                 for (int j = 0; j < 26; j++) {
//                     if (dist[i][k] < INF && dist[k][j] < INF) {
//                         dist[i][j] = min(dist[i][j], dist[i][k] +
//                         dist[k][j]);
//                     }
//                 }
//             }
//         }

//         // answer nikalte hai
//         ll ans = 0;
//         for (int i = 0; i < source.size(); i++) {
//             int s = source[i] - 'a';
//             int t = target[i] - 'a';
//             if (dist[s][t] == INF)
//                 return -1;
//             ans += dist[s][t];
//         }

//         return ans;
//     }
// };