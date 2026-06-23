class Solution {
public:
    unordered_map<int, list<int>> adjList;
    vector<int> baseTime;

    long long dfs(int node) {

        // Leaf node
        if (adjList[node].empty()) {
            return baseTime[node];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        for (auto child : adjList[node]) {

            long long childFinishTime = dfs(child);

            earliest = min(earliest, childFinishTime);
            latest = max(latest, childFinishTime);
        }

        long long ownDuration =
            (latest - earliest) + baseTime[node];

        return latest + ownDuration;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        this->baseTime = baseTime;

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
        }

        return dfs(0);
    }
};