class SegmentTree {      // Range Maximum Query
private:
    vector<int> segTree; // stores index of max element in range
    vector<int> arr;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);
        int leftIdx = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];
        segTree[i] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return -1;
        if (ql <= l && r <= qr) return segTree[i];
        int mid = l + (r - l) / 2;
        int left = query(2 * i + 1, l, mid, ql, qr);
        int right = query(2 * i + 2, mid + 1, r, ql, qr);
        if (left == -1) return right;
        if (right == -1) return left;
        return (arr[left] >= arr[right]) ? left : right;
    }

    void update(int i, int l, int r, int idx, int value) {
        if (l == r) {
            arr[idx] = value;
            segTree[i] = idx;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(2 * i + 1, l, mid, idx, value);
        else
            update(2 * i + 2, mid + 1, r, idx, value);
        int leftIdx = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];
        segTree[i] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

public:
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        segTree.resize(4 * n);
        build(0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int get(int idx){
        return arr[idx];
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree seg(baskets);
        int unplaced = 0;
        int n = baskets.size();

        for (int fruit : fruits) {
            int maxIdx = seg.query(0, n - 1);
            if (seg.get(maxIdx) < fruit) {
                unplaced++;
                continue;
            }

            // Binary search for leftmost valid basket
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int idx = seg.query(l, mid);
                if (idx != -1 && seg.get(idx) >= fruit) {
                    ans = idx;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // Mark that basket as used
            if (ans != -1) {
                seg.update(ans, INT_MIN); // basket used
            } else {
                unplaced++;
            }
        }

        return unplaced;
    }
};