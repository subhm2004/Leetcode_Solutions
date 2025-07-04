class SegmentTree {
private:
    int n;
    vector<unordered_map<int, int>> segTree;

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            segTree[node][arr[l]] = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);

        for (const auto& [val, freq] : segTree[2 * node + 1])
            segTree[node][val] += freq;

        for (const auto& [val, freq] : segTree[2 * node + 2])
            segTree[node][val] += freq;
    }

    int query(int node, int l, int r, int ql, int qr, int value) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return segTree[node].count(value) ? segTree[node][value] : 0;
        }

        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, ql, qr, value) +
               query(2 * node + 2, mid + 1, r, ql, qr, value);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int rangeFreq(int left, int right, int value) {
        return query(0, 0, n - 1, left, right, value);
    }
};

class RangeFreqQuery {
private:
    SegmentTree* A;

public:
    RangeFreqQuery(vector<int>& arr) {
        A = new SegmentTree(arr);
    }

    int query(int left, int right, int value) {
        return A->rangeFreq(left, right, value);
    }
};
