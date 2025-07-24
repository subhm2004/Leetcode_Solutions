class Solution {
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, int> subtree_xor;
    unordered_map<int, int> in_timer, out_timer;
    vector<pair<int, int>> edges;
    int timer = 0;

    void dfs(int node, int parent, vector<int>& nums) {
        in_timer[node] = ++timer;
        subtree_xor[node] = nums[node];

        for (int child : adjList[node]) {
            if (child == parent) continue;
            dfs(child, node, nums);
            subtree_xor[node] ^= subtree_xor[child];
            edges.push_back({node, child});   
        }

        out_timer[node] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return in_timer[u] < in_timer[v] && out_timer[v] < out_timer[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& inputEdges) {
        int n = nums.size();

        for (auto& edge : inputEdges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(0, -1, nums);
        int total_xor = subtree_xor[0];
        int ans = INT_MAX;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].second;
            for (int j = i + 1; j < edges.size(); ++j) {
                int v = edges[j].second;

                int x1, x2, x3;
                if (is_ancestor(u, v)) {
                    x2 = subtree_xor[v];
                    x1 = subtree_xor[u] ^ subtree_xor[v];
                    x3 = total_xor ^ subtree_xor[u];
                } else if (is_ancestor(v, u)) {
                    x1 = subtree_xor[u];
                    x2 = subtree_xor[v] ^ subtree_xor[u];
                    x3 = total_xor ^ subtree_xor[v];
                } else {
                    x1 = subtree_xor[u];
                    x2 = subtree_xor[v];
                    x3 = total_xor ^ x1 ^ x2;
                }

                ans = min(ans, max({x1, x2, x3}) - min({x1, x2, x3}));
            }
        }

        return ans;
    }
};
