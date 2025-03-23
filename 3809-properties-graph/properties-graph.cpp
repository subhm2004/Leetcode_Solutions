class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& A, int k) {
        int n = A.size();
        vector<unordered_set<int>> sets(n);
        UnionFind uf(n);

        // Convert each list into an unordered_set
        for (int i = 0; i < n; i++) {
            for (int x : A[i]) {
                sets[i].insert(x);
            }
        }

        // Check for common elements and union sets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int commonCount = 0;
                for (int x : sets[i]) {
                    if (sets[j].count(x)) {
                        commonCount++;
                        if (commonCount >= k) {
                            uf.unionByRank(i, j);
                            break;
                        }
                    }
                }
            }
        }

        // Count unique components
        unordered_set<int> components;
        for (int i = 0; i < n; i++) 
            components.insert(uf.find(i));

        return components.size();
    }
};


