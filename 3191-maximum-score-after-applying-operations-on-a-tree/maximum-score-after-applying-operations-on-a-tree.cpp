class Solution {
public:

    unordered_map<int, list<int>> adjList;
    long long total_sum = 0;

    long long dfs(int node, int parent, vector<int>& values) {

        // Leaf node
        if (adjList[node].size() == 1 && parent != -1)
            return values[node];

        long long child_cost = 0;

        for (auto child : adjList[node]) {

            if (child == parent)
                continue;

            child_cost += dfs(child, node, values);
        }

        return min((long long)values[node], child_cost);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {

        adjList.clear();
        total_sum = 0;

        int n = values.size();

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int val : values)
            total_sum += val;

        long long min_sacrifice = dfs(0, -1, values);

        return total_sum - min_sacrifice;
    }
};