class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build_Tree(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            segTree[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build_Tree(nums, 2 * i, l, mid);
        build_Tree(nums, 2 * i + 1, mid + 1, r);
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }

    void update(int i, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * i, l, mid, pos, val);
        else
            update(2 * i + 1, mid + 1, r, pos, val);
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }

    int query(int i, int l, int r, int start, int right) {
        if (right < l || start > r) return 0;
        if (start <= l && r <= right) return segTree[i];
        int mid = (l + r) / 2;
        return query(2 * i, l, mid, start, right) +
               query(2 * i + 1, mid + 1, r, start, right);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        build_Tree(nums, 1, 0, n - 1);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class NumArray {
private:
    SegmentTree* segTree;

public:
    NumArray(vector<int>& nums) {
        segTree = new SegmentTree(nums);
    }

    void update(int i, int val) {
        segTree->update(i, val);
    }

    int sumRange(int left, int right) {
        return segTree->query(left, right);
    }

    ~NumArray() {
        delete segTree;
    }
};
