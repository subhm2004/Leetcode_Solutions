class SegmentTree {
private:
    vector<int> segTree; // 0-indexed: node 0 = root, children = 2*node+1, 2*node+2
    int n;

    int AND(int a, int b) { return a & b; }

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) { // leaf → single element
            segTree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);
        segTree[node] = AND(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return -1; // no overlap → AND ka identity (saare bits 1)
        if (ql <= l && r <= qr)
            return segTree[node]; // full overlap → ready value

        int mid = l + (r - l) / 2; // partial → dono taraf jao
        return AND(query(2 * node + 1, l, mid, ql, qr), query(2 * node + 2, mid + 1, r, ql, qr));
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid)
            update(2 * node + 1, l, mid, pos, val);
        else
            update(2 * node + 2, mid + 1, r, pos, val);
        segTree[node] = AND(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.assign(4 * n, -1);
        build(arr, 0, 0, n - 1); // root = 0
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int pos, int val) { update(0, 0, n - 1, pos, val); }
};

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        SegmentTree seg(arr);

        int ans = INT_MAX;

        // Har left endpoint l fix karke best right endpoint dhoondho
        for (int l = 0; l < n; l++) {
            int low = l, high = n - 1;

            // ===== KEY INSIGHT =====
            // f(r) = AND of arr[l..r] monotonically NON-INCREASING hai in r,
            // kyunki AND sirf bits clear kar sakta hai, kabhi set nahi.
            // → monotonic → binary search valid.
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int value = seg.query(l, mid);

                // Har probe par update — isse crossover point ke dono
                // taraf ke candidates automatically cover ho jaate hain
                ans = min(ans, abs(value - target));

                if (value > target)
                    low = mid + 1; // range badhao → value ghategi
                else if (value < target)
                    high = mid - 1; // range ghatao → value badhegi
                else
                    return 0; // exact match
            }
        }
        return ans;
    }
};