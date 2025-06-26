class UnionFind {
public:
    vector<int> parent;
    vector<long long> segment_Sum;

    UnionFind(int n) {
        parent.resize(n);
        segment_Sum.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void setValue(int i, long long value) {
        segment_Sum[i] = value;
    }

    void unionSets(int i1, int i2) {
        int root1 = find(i1);
        int root2 = find(i2);
        if (root1 == root2) return;

        // Merge root2 into root1
        parent[root2] = root1;
        segment_Sum[root1] += segment_Sum[root2];
    }

    long long getSegment_Sum(int i) {
        return segment_Sum[find(i)];
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        UnionFind uf(n);
        vector<bool> isActive(n, false);
        vector<long long> ans(n);
        long long maxSegment_Sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = maxSegment_Sum;
            int curr_idx = removeQueries[i];
            isActive[curr_idx] = true;

            // Create new segment
            uf.setValue(curr_idx, nums[curr_idx]);

            // Merge with left neighbor if active
            if (curr_idx > 0 && isActive[curr_idx - 1]) {
                uf.unionSets(curr_idx, curr_idx - 1);
            }

            // Merge with right neighbor if active
            if (curr_idx < n - 1 && isActive[curr_idx + 1]) {
                uf.unionSets(curr_idx, curr_idx + 1);
            }

            // Update max segment sum
            maxSegment_Sum = max(maxSegment_Sum, uf.getSegment_Sum(curr_idx));
        }

        return ans;
    }
};
