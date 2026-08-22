class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            segTree[node] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, 2 * node + 1, l, mid);
        build(nums, 2 * node + 2, mid + 1, r);
        segTree[node] = segTree[2 * node + 1] & segTree[2 * node + 2];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return -1; 
        if (ql <= l && r <= qr)
            return segTree[node];
        int mid = l + (r - l) / 2;
        return query(2 * node + 1, l, mid, ql, qr) &
               query(2 * node + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4 * n, -1);
        build(nums, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class Solution {
private:
    int n;

    // Sabse chhota r ∈ [l, n-1] jahan AND(nums[l..r]) < x. Nahi mila to n
    // return. Valid hai kyunki f(r) = AND(l..r) non-increasing hai (AND sirf
    // bits clear karta hai) → predicate "f(r) < x" ek baar true hone ke baad
    // hamesha true.
    int first_less(SegmentTree& seg, int l, long long x) {
        int low = l;
        int high = n - 1;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (seg.query(l, mid) < x) {
                ans = mid;
                high = mid - 1; // aur left me try karo
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        SegmentTree seg(nums);

        long long ans = 0;
        for (int l = 0; l < n; l++) {

            int start = first_less(seg, l, k + 1); // pehla r jahan f(r) <= k
            int end = first_less(seg, l, k);       // pehla r jahan f(r) <  k
            ans += end - start; // beech ka block = exactly k wale subarrays

        }
        return ans;
    }
};