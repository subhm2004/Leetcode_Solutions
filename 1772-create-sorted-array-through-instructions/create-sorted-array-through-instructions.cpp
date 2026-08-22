class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(int node, int l, int r) {

        if (l == r) {
            segTree[node] = 0;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);

        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }

    void update(int node, int l, int r, int pos) {

        if (l == r) {
            segTree[node]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(2 * node + 1, l, mid, pos);
        else
            update(2 * node + 2, mid + 1, r, pos);

        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }

    int query(int node, int l, int r, int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return segTree[node];

        int mid = l + (r - l) / 2;

        int left = query(2 * node + 1, l, mid, ql, qr);

        int right = query(2 * node + 2, mid + 1, r, ql, qr);

        return left + right;
    }

public:
    SegmentTree(int size) {

        n = size;

        segTree.assign(4 * n + 5, 0);

        // Initially saare elements ki frequency 0 hai
        build(0, 1, n);
    }

    void update(int pos) { update(0, 1, n, pos); }

    int query(int l, int r) {

        if (l > r)
            return 0;

        return query(0, 1, n, l, r);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {

        const int MOD = 1e9 + 7;
        const int MAX_VALUE = 1e5;

        SegmentTree seg(MAX_VALUE);

        long long ans = 0;

        for (int x : instructions) {

            // x se strictly chhote
            int less = seg.query(1, x - 1);

            // x se strictly bade
            int greater = seg.query(x + 1, MAX_VALUE);

            // Current insertion ka cost
            ans = (ans + min(less, greater)) % MOD;

            // x ko nums mein insert karo
            seg.update(x);
        }

        return ans;
    }
};