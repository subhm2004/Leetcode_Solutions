class Solution {
public:
    using T = tuple<int, int, int>;

    unordered_map<int, list<pair<int, int>>> adjList;

    vector<vector<int>> dijkstra(int n, int maxTime, vector<int>& fees) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INF));

        priority_queue<T, vector<T>, greater<>> pq;

        dist[0][0] = fees[0];

        pq.push({fees[0], 0, 0});

        while (!pq.empty()) {

            auto [cost, u, time] = pq.top();
            pq.pop();

            if (cost != dist[u][time])
                continue;

            for (auto& [v, travel_time] : adjList[u]) {

                int new_tme = time + travel_time;

                if (new_tme > maxTime)
                    continue;

                int new_cost = cost + fees[v];

                if (new_cost < dist[v][new_tme]) {

                    dist[v][new_tme] = new_cost;

                    pq.push({new_cost, v, new_tme});
                }
            }
        }

        return dist;
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        adjList.clear();

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        vector<vector<int>> dist = dijkstra(n, maxTime, passingFees);

        int ans = 1e9;

        for (int time = 0; time <= maxTime; time++) {
            ans = min(ans, dist[n - 1][time]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};