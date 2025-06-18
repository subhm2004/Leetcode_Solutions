class SegmentTree {
private:
    vector<int> segTree, lazy;
    int n;

    void build(const vector<int> &arr, int i, int l, int r) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*i+1, l, mid);
        build(arr, 2*i+2, mid+1, r);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void push(int i, int l, int r) {
        if (lazy[i]) {
            segTree[i] = (r - l + 1) - segTree[i];
            if (l != r) {
                lazy[2*i+1] ^= 1;
                lazy[2*i+2] ^= 1;
            }
            lazy[i] = 0;
        }
    }

    void updateRange(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[i] ^= 1;
            push(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        updateRange(2*i+1, l, mid, ql, qr);
        updateRange(2*i+2, mid+1, r, ql, qr);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return segTree[i];
        int mid = (l + r) / 2;
        return query(2*i+1, l, mid, ql, qr) + query(2*i+2, mid+1, r, ql, qr);
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        segTree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void flipRange(int l, int r) {
        updateRange(0, 0, n - 1, l, r);
    }

    int countOnes() {
        return query(0, 0, n - 1, 0, n - 1);
    }
};
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree seg(nums1);
        long long total = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                seg.flipRange(q[1], q[2]);
            } else if (q[0] == 2) {
                long long count = seg.countOnes();
                total += count * q[1];
            } else {
                ans.push_back(total);
            }
        }

        return ans;
    }
};
