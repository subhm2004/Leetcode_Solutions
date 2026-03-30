class Solution {
private:
    vector<vector<int>> adj;
    vector<long long> dp, ans;
    vector<int> val; // +1 / -1
    int n;


    long long BASE(int node) {
        return val[node]; // +1 or -1
    }

    long long COMBINE(long long parent_dp, long long child_dp) {
        return parent_dp + max(0LL, child_dp);
    }

    long long REMOVE(long long parent_dp, long long child_dp) {
        return parent_dp - max(0LL, child_dp);
    }

    // Bottom-up DFS (subtree info)
    void dfs1(int node, int parent) {
        dp[node] = BASE(node);

        for (int child : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node);
            dp[node] = COMBINE(dp[node], dp[child]);
        }
    }

    // Rerooting DFS
    void dfs2(int node, int parent) {
        ans[node] = dp[node];

        for (int child : adj[node]) {
            if (child == parent) continue;

            // save state
            long long oldNode  = dp[node];
            long long oldChild = dp[child];

            // remove
            dp[node]  = REMOVE(dp[node], dp[child]);
            // combine
            dp[child] = COMBINE(dp[child], dp[node]);

            // recurse
            dfs2(child, node);

            // restore
            dp[node]  = oldNode;
            dp[child] = oldChild;
        }
    }

public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        this->n = n;

        adj.assign(n, {});
        dp.assign(n, 0);
        ans.assign(n, 0);
        val.assign(n, 0);

        // convert good/bad → +1 / -1
        for (int i = 0; i < n; i++) {
            val[i] = (good[i] == 1 ? 1 : -1);
        }

        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        // convert to int
        vector<int> result(ans.begin(), ans.end());

        return result;
    }
};