class SegmentTree {
private:
    vector<int> segTree;  // Stores count of available positions in each segment
    int n;               // Size of original array

public:
    // Constructor: Initialize segment tree with given size
    SegmentTree(int size) {
        n = size;
        segTree.resize(4 * n, 0);  // 4*n size needed for complete binary tree
        build(0, 0, n - 1);        // Build tree: node=0, range=[0,n-1]
    }

    // Build segment tree recursively - initially all positions are available
    void build(int node, int left, int right) {
        // Base case: leaf node represents single position
        if (left == right) {
            segTree[node] = 1;  // Mark position as available (1 = available, 0 = used)
            return;
        }
        
        // Recursive case: build left and right subtrees
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);        // Left child: range [left, mid]
        build(2 * node + 2, mid + 1, right);   // Right child: range [mid+1, right]
        
        // Current node stores sum = total available positions in its range
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }

    // Find k-th available position (k is 1-indexed)
    // Logic: Go left if k <= leftCount, else go right with adjusted k
    int query(int node, int left, int right, int k) {
        // Base case: reached leaf node, return the position
        if (left == right) return left;

        int mid = (left + right) / 2;
        int leftCount = segTree[2 * node + 1];  // Available positions in left subtree

        // Decision: where is the k-th available position?
        if (k <= leftCount) {
            // k-th position is in left subtree
            return query(2 * node + 1, left, mid, k);
        } else {
            // k-th position is in right subtree
            // Since left has leftCount positions, we need (k-leftCount)th in right
            return query(2 * node + 2, mid + 1, right, k - leftCount);
        }
    }

    // Mark position idx as used (change from 1 to 0)
    void update(int node, int left, int right, int idx) {
        // Base case: reached the target position
        if (left == right) {
            segTree[node] = 0;  // Mark as used (0 = not available)
            return;
        }

        // Recursive case: find which subtree contains idx
        int mid = (left + right) / 2;
        if (idx <= mid) {
            update(2 * node + 1, left, mid, idx);      // Update in left subtree
        } else {
            update(2 * node + 2, mid + 1, right, idx); // Update in right subtree
        }
        
        // Propagate change upward: recalculate current node's sum
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        // STEP 1: Sort by height ASC, then k DESC
        // WHY? Process shorter people first so taller people placed later don't interfere
        // For same height, larger k first to avoid position conflicts
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];  // Primary: height ascending
            return a[1] > b[1];                   // Secondary: k descending
        });

        vector<vector<int>> ans(n);  // Result array to be filled
        SegmentTree st(n);           // Track which positions are available

        // STEP 2: Process each person in sorted order
        for (auto& person : people) {
            int height = person[0];  // Person's height
            int k = person[1];       // Number of people >= height should be in front
            
            // STEP 3: Find (k+1)th available position
            // Why k+1? Because k is 0-indexed but query expects 1-indexed
            int pos = st.query(0, 0, n - 1, k + 1);
            
            // STEP 4: Place person at found position
            ans[pos] = person;
            
            // STEP 5: Mark this position as occupied
            st.update(0, 0, n - 1, pos);
        }

        return ans;
    }
};