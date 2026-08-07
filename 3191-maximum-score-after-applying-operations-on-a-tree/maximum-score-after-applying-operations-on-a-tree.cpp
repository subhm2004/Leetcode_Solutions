using ll = long long;
class Solution {
public:
    unordered_map<int, list<int>> adjList;
    ll total_sum = 0;

    ll dfs(int node, int parent, vector<int>& values) {

        // BC(Leaf node)
        if (adjList[node].size() == 1 && parent != -1)
            return values[node];

        ll child_cost = 0;

        for (auto child : adjList[node]) {

            if (child == parent)
                continue;

            child_cost += dfs(child, node, values);
        }

        return min(1LL * values[node], child_cost);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges,
                                          vector<int>& values) {
        adjList.clear();

        total_sum = accumulate(values.begin(), values.end(), 0LL);

        int n = values.size();

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        ll min_sacrifice = dfs(0, -1, values);

        return total_sum - min_sacrifice;
    }
};