class UnionFind {
public:
    vector<int> parent, rank, size;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void union_By_Rank(int x, int y, int &max_Len) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return; // Already in the same set

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
            max_Len = max(max_Len, size[y_parent]);
        } 
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
            max_Len = max(max_Len, size[x_parent]);
        } 
        else { //rank[x_parent] == rank[y_parent ] same rank hogyi 
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
            rank[y_parent]++;
            max_Len = max(max_Len, size[y_parent]);
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> num_To_Index;
        int n = nums.size();
        UnionFind uf(n);
        int max_Len = 1;

        for (int i = 0; i < n; i++) {
            if (num_To_Index.count(nums[i])) continue; // Ignore duplicates
            num_To_Index[nums[i]] = i;

            if (num_To_Index.count(nums[i] - 1)) {
                uf.union_By_Rank(i, num_To_Index[nums[i] - 1], max_Len);
            }
            if (num_To_Index.count(nums[i] + 1)) {
                uf.union_By_Rank(i, num_To_Index[nums[i] + 1], max_Len);
            }
        }

        return max_Len;
    }
};
