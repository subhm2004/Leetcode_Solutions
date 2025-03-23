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
        if (rootX == rootY)
            return;

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
        vector<unordered_set<int>> sets(n); // Har list ke liye ek unordered_set
        UnionFind uf(n); // Disjoint Set Union (DSU) banaya

        // **Step 1: Convert har list ko unordered_set me**
        // Yeh optimize karta hai common elements ke lookup ko O(1) me.
        for (int i = 0; i < n; i++) {
            for (int x : A[i]) {
                sets[i].insert(x);
            }
        }

        // **Step 2: Har pair of sets ke beech check karo ki kya unme k common elements hain**
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int commonCount = 0;

                // Set `i` ke har element ke liye check karenge ki kya `j` ke set me bhi hai
                for (int x : sets[i]) {
                    if (sets[j].count(x)) { // Agar x dono sets me hai toh count badhayein
                        commonCount++;
                        if (commonCount >= k) { // Agar k ya zyada common elements mil gaye toh
                            uf.unionByRank(i, j); // Dono sets ko ek component me merge kar do
                            break; // Ek baar merge ho gaya toh aur check karne ki zaroorat nahi
                        }
                    }
                }
            }
        }

        // **Step 3: Har unique component ko count karna**
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (uf.find(i) == i) // Sirf root nodes ko count karna hai
                count++;
        }

        return count; // Total number of connected components return karna hai
    }
};

