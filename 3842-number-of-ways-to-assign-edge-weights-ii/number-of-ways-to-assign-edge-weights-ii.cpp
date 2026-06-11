class BinaryLifting {
private:
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    unordered_map<int, list<int>> adjList;

public:
    BinaryLifting(int n, vector<vector<int>>& edges) {
        this->n = n;
        LOG = ceil(log2(n + 1)) + 1;
        up.assign(n + 1, vector<int>(LOG, 1)); // default = root(1)
        depth.assign(n + 1, 0);

        // edges se adjacency list banao
        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);  
            adjList[e[1]].push_back(e[0]);  
        }

        dfs(1, 1, 0); // root=1, parent=1, depth=0
    }

    //O(n) DFS  
    void dfs(int node, int parent, int d) {
        depth[node] = d;
        up[node][0] = parent;

        // up table fill karo
        for (int j = 1; j < LOG; j++)
            up[node][j] = up[up[node][j - 1]][j - 1];

        for (int child : adjList[node])
            if (child != parent)
                dfs(child, node, d + 1);
    }

    int get_Kth_Ancestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
        }
        return node;
    }

    int get_LCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        u = get_Kth_Ancestor(u, depth[u] - depth[v]); // same level pe lao

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--)
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }

        return up[u][0];
    }

    int get_Depth(int node) { return depth[node]; }
};

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binary_expo(long long base, long long exp, long long mod) {
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1)
                ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        BinaryLifting bl(n, edges);

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int l = bl.get_LCA(u, v);
            int k = bl.get_Depth(u) + bl.get_Depth(v) - 2 * bl.get_Depth(l);

            if (k == 0)
                ans.push_back(0);
            else
                ans.push_back(binary_expo(2, k - 1, MOD));
        }
        return ans;
    }
};