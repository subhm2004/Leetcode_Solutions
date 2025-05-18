// https://www.youtube.com/watch?v=B3Wgf-g6i-k
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> weight;

    UnionFind(int n) : parent(n), rank(n, 0), weight(n, INT_MAX) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unionByRank(int x, int y, int w) {
        int x_parent = find(x);
        int y_parent = find(y);
        int newWeight = weight[x_parent] & weight[y_parent] & w;

        weight[x_parent] = newWeight;
        weight[y_parent] = newWeight;

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int getMinCost(int u, int v) {
        if (u == v)
            return 0;
        int u_parent = find(u);
        int v_parent = find(v);
        return (u_parent == v_parent) ? weight[u_parent] : -1;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        UnionFind uf(n);
        vector<int> ans;

        for (auto& edge : edges) {
            uf.unionByRank(edge[0], edge[1], edge[2]);
        }

        for (auto& query : queries) {
            ans.push_back(uf.getMinCost(query[0], query[1]));
        }

        return ans;
    }
};
