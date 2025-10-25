// prefixSum[i] ka matlab hota hai: nums[0] + nums[1] + ... + nums[i - 1]

// class NumArray {
// public:
//     vector<int> prefixSum;  
//      NumArray(vector<int>& nums) {
//          prefixSum = vector<int>(nums.size() + 1, 0);

//          for (int i = 0; i < nums.size(); ++i) {
//              prefixSum[i + 1] = prefixSum[i] + nums[i];
//         }
//     }

//      int sumRange(int left, int right) {
//          return prefixSum[right + 1] - prefixSum[left];
//     }
// };


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
        build_Tree(nums, 2 * i + 1, l, mid);
        build_Tree(nums, 2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update(int i, int l, int r, int pos, int val) {
        if (l == r) {
            segTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * i + 1, l, mid, pos, val);
        else
            update(2 * i + 2, mid + 1, r, pos, val);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return segTree[i];
        int mid = (l + r) / 2;
        return query(2 * i + 1, l, mid, ql, qr) +
               query(2 * i + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        build_Tree(nums, 0, 0, n - 1);
    }

    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
class NumArray {
private:
    SegmentTree* segTree;

public:
    NumArray(vector<int>& nums) {
        segTree = new SegmentTree(nums);
    }

    // void update(int i, int val) {
    //     segTree->update(i, val);
    // }

    int sumRange(int left, int right) {
        return segTree->query(left, right);
    }

    ~NumArray() {
        delete segTree;
    }
};
