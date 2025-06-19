class SegmentTree {
private:
    vector<int> segTree, lazy;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            segTree[i] = INT_MAX;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
    }

    void push(int i, int l, int r) {
        if (lazy[i] != INT_MAX) {
            segTree[i] = min(segTree[i], lazy[i]);
            if (l != r) {
                lazy[2 * i] = min(lazy[2 * i], lazy[i]);
                lazy[2 * i + 1] = min(lazy[2 * i + 1], lazy[i]);
            }
            lazy[i] = INT_MAX;
        }
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        push(i, l, r);
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[i] = val;
            push(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(2 * i, l, mid, ql, qr, val);
        update(2 * i + 1, mid + 1, r, ql, qr, val);
        segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r < ql || l > qr) return INT_MAX;
        if (ql <= l && r <= qr) return segTree[i];

        int mid = (l + r) / 2;
        return min(
            query(2 * i, l, mid, ql, qr),
            query(2 * i + 1, mid + 1, r, ql, qr)
        );
    }

public:
    SegmentTree(int _n) : n(_n), segTree(4 * _n, INT_MAX), lazy(4 * _n, INT_MAX) {
        build(1, 0, n - 1);
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<int> coordinates;
        for (auto& it : intervals) {
            coordinates.insert(it[0]);
            coordinates.insert(it[1]);
        }
        for (int q : queries) coordinates.insert(q);

        unordered_map<int, int> compress;
        int idx = 0;
        for (int x : coordinates) compress[x] = idx++;

        int N = compress.size();
        SegmentTree seg(N);

        for (auto& it : intervals) {
            int l = compress[it[0]];
            int r = compress[it[1]];
            int size = it[1] - it[0] + 1;
            seg.update(l, r, size);
        }

        vector<int> ans;
        for (int q : queries) {
            int cq = compress[q];
            int res = seg.query(cq, cq);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};
