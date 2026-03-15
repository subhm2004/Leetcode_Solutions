class UnionFind {
public:
    vector<int> parent, rank;

    // Constructor to initialize parent and rank
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find function with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Union function by rank
    void union_by_rank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return; // Already in the same set

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        unordered_map<int, int> row_map;
        unordered_map<int, int> col_map;

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            // Union by row
            if (row_map.count(x)) {
                uf.union_by_rank(i, row_map[x]);
            } else {
                row_map[x] = i;
            }

            // Union by column
            if (col_map.count(y)) {
                uf.union_by_rank(i, col_map[y]);
            } else {
                col_map[y] = i;
            }
        }

        // Count unique components
        unordered_set<int> unique_parents;
        for (int i = 0; i < n; i++) {
            unique_parents.insert(uf.find(i));
        }

        return n - unique_parents.size(); // Stones that can be removed
    }
};
