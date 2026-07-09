class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void UNION_BY_RANK(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else if (rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        UnionFind uf(n);

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                uf.UNION_BY_RANK(i, i + 1);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(uf.find(u) == uf.find(v));
        }

        return ans;
    }
};