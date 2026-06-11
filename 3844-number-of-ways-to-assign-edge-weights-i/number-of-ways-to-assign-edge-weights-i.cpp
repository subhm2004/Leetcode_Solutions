class Solution {
public:
    unordered_map<int, list<int>> adjList;
    vector<bool> visited;
    int max_depth = 0;

    void dfs(int node, int curr_depth) {
        visited[node] = true;
        max_depth = max(max_depth, curr_depth);

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, curr_depth + 1);
            }
        }
    }

    // (help krega depth find krne me graph like tree)
    int find_max_depth(int n) {
        visited.assign(n + 1, false);
        max_depth = 0;
        dfs(1, 0); // root = 1, depth = 0
        return max_depth;
    }

    long long binary_expo(long long base, long long exp, long long MOD) {
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1)
                ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int depth = find_max_depth(n);

        return binary_expo(2, depth - 1, MOD); // 2 ^ (depth - 1)
    }
    
};