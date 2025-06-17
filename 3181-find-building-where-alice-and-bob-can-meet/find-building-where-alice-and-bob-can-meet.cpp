class SegmentTree {
private:
    vector<int> segTree; // stores index of max element in range
    vector<int> arr;     // input array
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
        if (r < ql || l > qr)
            return -1;
        if (ql <= l && r <= qr)
            return segTree[i];

        int mid = l + (r - l) / 2;
        int left = query(2 * i + 1, l, mid, ql, qr);
        int right = query(2 * i + 2, mid + 1, r, ql, qr);

        if (left == -1)
            return right;
        if (right == -1)
            return left;
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

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int idx, int value) { update(0, 0, n - 1, idx, value); }

    int get(int idx) const { return arr[idx]; }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree seg(heights);
        vector<int> result;

        for (auto& query : queries) {
            int a = query[0];
            int b = query[1];

            int alice = min(a, b);
            int bob = max(a, b);

            if (alice == bob || heights[bob] > heights[alice]) {
                result.push_back(bob);
                continue;
            }

            int l = max(a, b) + 1, r = n - 1;
            int ans = INT_MAX;

            while (l <= r) {
                int mid = (l + r) >> 1;
                int idx = seg.query(l, mid);

                if (idx != -1 && heights[idx] > heights[a] &&
                    heights[idx] > heights[b]) {
                    ans = min(ans, idx);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            result.push_back(ans == INT_MAX ? -1 : ans);
        }

        return result;
    }
};
