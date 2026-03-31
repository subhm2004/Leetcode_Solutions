class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> dp, ans;
    int n;

    // BASE
    int BASE(int node) {
        return 0;
    }

    // COMBINE (child → parent) child ko parent me add
    int COMBINE(int parent_dp, int child_dp, int cost) {
        return parent_dp + child_dp + cost;
    }

    // REMOVE (child remove) child ko parent se remove
    int REMOVE(int parent_dp, int child_dp, int cost) {
        return parent_dp - (child_dp + cost);
    }

    // ADD (parent → child) parent ko child me add 
    int ADD(int child_dp, int parent_dp, int cost) {
        return child_dp + parent_dp + cost;
    }

    // dfs1
    void dfs1(int node, int parent) {
        dp[node] = BASE(node);

        for (auto &[child, cost] : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node);
            dp[node] = COMBINE(dp[node], dp[child], cost);
        }
    }

    // dfs2 (reroot)
    void dfs2(int node, int parent) {
        ans[node] = dp[node];

        for (auto &[child, cost] : adj[node]) {
            if (child == parent) continue;

            int old_node  = dp[node];
            int olde_child = dp[child];

            // REMOVE child contribution
            dp[node] = REMOVE(dp[node], dp[child], cost);

            // ADD parent contribution to child
            // reverse cost flip karna hoga
            int reverse_cost = (cost == 0 ? 1 : 0);

            dp[child] = ADD(dp[child], dp[node], reverse_cost);

            // recurse
            dfs2(child, node);

            // restore
            dp[node]  = old_node;
            dp[child] = olde_child;
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        this->n = n;

        adj.assign(n, {});
        dp.assign(n, 0);
        ans.assign(n, 0);

        // build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back({v, 0}); // correct direction
            adj[v].push_back({u, 1}); // reverse
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};