using T = tuple<long long, int, int>; // {time, node, remaining_power}
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {

        unordered_map<int, list<pair<int, int>>> adjList;
        for (auto& e : edges) {
            adjList[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        priority_queue<T, vector<T>, greater<>> pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [time, u, remaining_power] = pq.top();
            pq.pop();

            if (time > dist[u][remaining_power])
                continue;

            if (u == target)
                continue;

            if (remaining_power < cost[u])
                continue;

            int new_power = remaining_power - cost[u];

            if(adjList.find(u) == adjList.end()) continue;

            for (auto& [v, wt] : adjList.find(u)->second) {
                long long new_time = time + wt;  

                if (new_time < dist[v][new_power]) {
                    dist[v][new_power] = new_time;
                    pq.push({new_time, v, new_power});
                }
            }
        }

        // Target node ke har possible power-level 'p' ko check krte hai 
        // Hume chahiye: minimum time, aur usi minimum time pe maximum power
        long long min_time = INF;
        long long max_power =  -1; 

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < min_time) {

                min_time = dist[target][p];
                max_power = p;
            } else if (dist[target][p] == min_time) {
                
                max_power = max(max_power, 1LL * p);
            }
        }
        if (min_time == INF)
            return {-1, -1};

        return {min_time, max_power};
    }
};