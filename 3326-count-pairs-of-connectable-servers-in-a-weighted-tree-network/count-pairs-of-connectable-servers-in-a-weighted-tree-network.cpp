class Solution {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    int dfs(int node, int parent, long long dist, int signalSpeed) {

        int count = (dist % signalSpeed == 0);

        for (auto [nbr, wt] : adjList[node]) {

            if (nbr == parent)
                continue;

            count += dfs(nbr, node, dist + wt, signalSpeed);
        }

        return count;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {

        adjList.clear();

        int n = edges.size() + 1;

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        vector<int> ans(n);

        for (int center = 0; center < n; center++) {

            int previous = 0;

            for (auto [child, wt] : adjList[center]) {

                int current = dfs(child, center, wt, signalSpeed);

                ans[center] += previous * current;

                previous += current;
            }
        }

        return ans;
    }
};