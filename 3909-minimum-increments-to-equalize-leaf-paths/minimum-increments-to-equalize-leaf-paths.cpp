class Solution {
public:
    unordered_map<int, list<int>> adjList;
    long long ans = 0;

    // DFS to return max path sum from node to leaf
    long long dfs(vector<int>& cost, int node) {
        if (adjList[node].empty()) return cost[node];  // leaf node

        vector<long long> child_Path_Sums;

        for (int child : adjList[node]) {
            child_Path_Sums.push_back(dfs(cost, child));
        }

        long long maxPath = *max_element(child_Path_Sums.begin(), child_Path_Sums.end());

        // Count how many child paths are less than the max path
        for (auto& val : child_Path_Sums) {
            if (val != maxPath) ans++;
        }

        return cost[node] + maxPath; // max path sum
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        // Build the tree with directed edges: parent -> child
        vector<bool> has_Parent(n, false);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            has_Parent[v] = true;
        }

        // Find the root (node with no parent)
        int root = 0;
 
        dfs(cost, root);
        return ans;
    }
};
