class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<pair<int,int>> dp; // {distance_sum, subtree_size}
    int n;

    // BASE
    pair<int,int> BASE(int node) {
        return {0, 1}; // distance = 0, size = 1
    }

    // COMBINE (child → parent)
    pair<int,int> COMBINE(pair<int,int> parent, pair<int,int> child) {
        parent.first  += child.first + child.second;
        parent.second += child.second;
        return parent;
    }

    // REMOVE (child remove from parent)
    pair<int,int> REMOVE(pair<int,int> parent, pair<int,int> child) {
        parent.first  -= (child.first + child.second);
        parent.second -= child.second;
        return parent;
    }

    // ADD (parent → child)
    pair<int,int> ADD(pair<int,int> child, pair<int,int> parent) {
        child.first  += (parent.first + parent.second);
        child.second += parent.second;
        return child;
    }

    // Bottom-up DFS
    void dfs1(int node, int parent) {
        dp[node] = BASE(node);

        for (int child : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node);
            dp[node] = COMBINE(dp[node], dp[child]);
        }
    }

    // Reroot DFS
    void dfs2(int node, int parent) {
        ans[node] = dp[node].first;

        for (int child : adj[node]) {
            if (child == parent) continue;

            auto oldNode  = dp[node];
            auto oldChild = dp[child];

            // Rerooting using functions
            dp[node]  = REMOVE(dp[node], dp[child]);
            dp[child] = ADD(dp[child], dp[node]);

            dfs2(child, node);

            // restore
            dp[node]  = oldNode;
            dp[child] = oldChild;
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;

        adj.assign(n, {});
        dp.assign(n, {0, 0});
        ans.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};