using T = tuple<long long, int, int>;
class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int, list<pair<int, int>>> adjList;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;

        // {cost, node, streak}
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, node, streak] = pq.top();
            pq.pop();

            if (cost > dist[node][streak])
                continue;

            for (auto nbr : adjList[node]) {

                int next_node = nbr.first;
                int wt = nbr.second;

                int new_streak;

                if (labels[next_node] == labels[node])
                    new_streak = streak + 1;
                else
                    new_streak = 1;

                if (new_streak > k)
                    continue;

                long long new_cost = cost + wt;

                if (new_cost < dist[next_node][new_streak]) {

                    dist[next_node][new_streak] = new_cost;

                    pq.push({new_cost, next_node, new_streak});
                }
            }
        }

        long long ans = LLONG_MAX;

        for (int streak = 1; streak <= k; streak++) {
            ans = min(ans, dist[n - 1][streak]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};