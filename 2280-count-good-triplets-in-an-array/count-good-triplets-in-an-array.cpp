class SegmentTree {
private:
    vector<int> segTree;
    vector<int> arr;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            segTree[i] = 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return segTree[i];
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, ql, qr) +
               query(2 * i + 2, mid + 1, r, ql, qr);
    }

    void update(int i, int l, int r, int idx, int value) {
        if (l == r) {
            arr[idx] += value;
            segTree[i] += value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(2 * i + 1, l, mid, idx, value);
        else
            update(2 * i + 2, mid + 1, r, idx, value);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

public:
    SegmentTree(int size) {
        n = size;
        segTree.resize(4 * n);
        arr.assign(n, 0);
        build(0, 0, n - 1);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int get(int idx) {
        return arr[idx];
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> posInNums1;
        for (int i = 0; i < n; ++i)
            posInNums1[nums1[i]] = i;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = posInNums1[nums2[i]];

        vector<int> leftSmaller(n), rightLarger(n);
        SegmentTree leftTree(n), rightTree(n);

        for (int i = 0; i < n; ++i) {
            leftSmaller[i] = leftTree.query(0, arr[i] - 1);
            leftTree.update(arr[i], 1);
        }

        for (int i = n - 1; i >= 0; --i) {
            rightLarger[i] = rightTree.query(arr[i] + 1, n - 1);
            rightTree.update(arr[i], 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += 1LL * leftSmaller[i] * rightLarger[i];

        return ans;
    }
};
