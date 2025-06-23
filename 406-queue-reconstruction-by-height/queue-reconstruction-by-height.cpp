class SegmentTree {
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        build(1, 0, n - 1);
    }

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = 1;  // Initially all positions available
            return;
        }
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // find k-th available position (1-indexed k)
    int query(int node, int left, int right, int k) {
        if (left == right) {
            return left;
        }
        
        int mid = (left + right) / 2;
        int leftCount = tree[2 * node];
        
        if (k <= leftCount) {
            return query(2 * node, left, mid, k);
        } else {
            return query(2 * node + 1, mid + 1, right, k - leftCount);
        }
    }

    // Mark position as used
    void update(int node, int left, int right, int idx) {
        if (left == right) {
            tree[node] = 0;  // Mark as unavailable
            return;
        }
        int mid = (left + right) / 2;
        if (idx <= mid) {
            update(2 * node, left, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, right, idx);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        
        // Sort by height ascending, then k descending for same height
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] < b[0]) return true;   // Shorter height first
            if (a[0] > b[0]) return false;
            return a[1] > b[1];             // Larger k first for same height
        });
        
        vector<vector<int>> result(n);
        SegmentTree st(n);
        
        for (auto& person : people) {
            int k = person[1];
            // query (k+1)-th available position (convert 0-indexed k to 1-indexed)
            int pos = st.query(1, 0, n - 1, k + 1);
            result[pos] = person;
            st.update(1, 0, n - 1, pos);
        }
        
        return result;
    }
};

/*
EXAMPLE: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

After sorting (height asc, k desc): [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]

KEY INSIGHT: Process shorter people first!
- Shorter people won't affect taller people's k count
- For same height, process larger k first to avoid conflicts

Initial segment tree: All positions available

Process [4,4]: k=4, query 5th available position = index 4
Result: [_,_,_,_,[4,4],_]

Process [5,2]: k=2, query 3rd available position = index 2
Result: [_,_,[5,2],_,[4,4],_]

Process [5,0]: k=0, query 1st available position = index 0
Result: [[5,0],_,[5,2],_,[4,4],_]

Process [6,1]: k=1, query 2nd available position = index 1
Result: [[5,0],[6,1],[5,2],_,[4,4],_]

Process [7,1]: k=1, query 2nd available position = index 3
Result: [[5,0],[6,1],[5,2],[7,1],[4,4],_]

Process [7,0]: k=0, query 1st available position = index 5
Result: [[5,0],[6,1],[5,2],[7,1],[4,4],[7,0]]

This gives: [[5,0],[6,1],[5,2],[7,1],[4,4],[7,0]]
Expected:  [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

Still doesn't match! Need to reconsider the approach...
*/