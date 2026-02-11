class SegmentTree {
public:
    int n;
    vector<int> mini_segTree;
    vector<int> maxi_segTree;
    vector<int> lazy;

    SegmentTree(int _n) {
        n = _n;
        mini_segTree.assign(4*n, 0);
        maxi_segTree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void push(int i, int l, int r) {
        if (lazy[i] != 0) {
            mini_segTree[i] += lazy[i];
            maxi_segTree[i] += lazy[i];

            if (l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void range_update(int ql, int qr, int i, int l, int r, int val) {
        push(i, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[i] += val;
            push(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        range_update(ql, qr, 2*i+1, l, mid, val);
        range_update(ql, qr, 2*i+2, mid+1, r, val);

        mini_segTree[i] = min(mini_segTree[2*i+1], mini_segTree[2*i+2]);
        maxi_segTree[i] = max(maxi_segTree[2*i+1], maxi_segTree[2*i+2]);
    }

    int point_query(int idx, int i, int l, int r) {
        push(i, l, r);

        if (l == r) return mini_segTree[i];

        int mid = (l + r) / 2;
        if (idx <= mid)
            return point_query(idx, 2*i+1, l, mid);
        else
            return point_query(idx, 2*i+2, mid+1, r);
    }

    int first_equal(int ql, int qr, int X, int i, int l, int r) {
        push(i, l, r);

        if (r < ql || l > qr) return -1;
        if (mini_segTree[i] > X || maxi_segTree[i] < X) return -1;

        if (l == r) return l;

        int mid = (l + r) / 2;

        int left = first_equal(ql, qr, X, 2*i+1, l, mid);
        if (left != -1) return left;

        return first_equal(ql, qr, X, 2*i+2, mid+1, r);
    }

    // wrappers
    void range_update(int l, int r, int val) {
        if (l > r) return;
        range_update(l, r, 0, 0, n-1, val);
    }

    int point_query(int idx) {
        return point_query(idx, 0, 0, n-1);
    }

    int find_first_equal(int l, int r, int X) {
        if (l > r) return -1;
        return first_equal(l, r, X, 0, 0, n-1);
    }
};



class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        SegmentTree seg(n);

        unordered_map<int,int> last_occ;
        int ans = 0;

        for (int r = 0; r < n; r++) {

            int x = nums[r];
            int w = (x % 2 == 0 ? 1 : -1);

            if (last_occ.count(x)) {
                int p = last_occ[x];
                seg.range_update(p, n-1, -w);
            }

            seg.range_update(r, n-1, +w);

            last_occ[x] = r;

            int X = seg.point_query(r);

            int j = seg.find_first_equal(0, r-1, X);
            if (j != -1)
                ans = max(ans, r - j);

            if (X == 0)
                ans = max(ans, r + 1);
        }

        return ans;
    }
};
