class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<pair<int,int>>> adjList, rev_adjList;
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adjList[u].push_back({v, w});        // forward edges
            rev_adjList[v].push_back({u, w});    // reverse edges (incoming to v)
        }

        const long long INF = 1e18;
        
        // dist[node][switch_used_at_this_node]
        vector<vector<long long>> dist(n, vector<long long>(2, INF));

        // pq: {cost, node, switch_used_at_current_node}
        priority_queue< tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto [d, u, used_at_u] = pq.top();
            pq.pop();

            if (d > dist[u][used_at_u]) continue;

            // Option 1: Take forward edges (no switch needed)
            for (auto &[v, w] : adjList[u]) {
                long long nd = d + w;
                
                // Arrive at v without using v's switch
                if (nd < dist[v][0]) {
                    dist[v][0] = nd;
                    pq.emplace(nd, v, 0);
                }
            }

            // Option 2: Use switch at u (if not already used)
            if (used_at_u == 0) {
                // Reverse incoming edges to u and traverse them
                for (auto &[v, w] : rev_adjList[u]) {
                    long long nd = d + 2LL * w;
                    
                    // Arrive at v, and we've used u's switch (not v's)
                    if (nd < dist[v][0]) {
                        dist[v][0] = nd;
                        pq.emplace(nd, v, 0);
                    }
                }
            }
        }

        long long ans = min(dist[n-1][0], dist[n-1][1]);
        return ans == INF ? -1 : ans;
    }
};