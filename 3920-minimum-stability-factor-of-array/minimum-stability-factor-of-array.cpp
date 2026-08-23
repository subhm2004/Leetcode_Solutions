class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) { segTree[node] = nums[l]; return; }
        int mid = l + (r - l) / 2;
        build(nums, 2 * node + 1, l, mid);
        build(nums, 2 * node + 2, mid + 1, r);
        segTree[node] = gcd(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;   // gcd ka IDENTITY = 0, kyunki gcd(0, x) = x
        if (ql <= l && r <= qr) return segTree[node];
        int mid = l + (r - l) / 2;
        return gcd(query(2 * node + 1, l,       mid, ql, qr),
                   query(2 * node + 2, mid + 1, r,   ql, qr));
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};


class Solution {
private:
    int n;

    // Kya at most maxC changes me stability factor <= L laaya ja sakta hai?
    // Modified element ko 1 maan lo → gcd(x, 1) = 1 → us index ko contain karne
    // wala har subarray dead. To problem = "saare bad windows ko stab karo".
    bool is_possible(SegmentTree& seg, int maxC, int L) {
        int last_modified_idx = -1;   // last index jise modify kiya
        int changes = 0;

        for (int l = 0; l + L < n; l++) {
            // Window [l, l+L] me pehle se modified element hai → already dead.
            // Sirf `l <= last_modified_idx` check kaafi hai, kyunki last_modified_idx humesha kisi
            // PICHHLE window ka right end tha → last_modified_idx < l+L guaranteed.
            if (l <= last_modified_idx) continue;

            int r = l + L;
            if (seg.query(l, r) >= 2) {       // bad window → stab karna padega
                if (++changes > maxC) return false;
                last_modified_idx = r;                  // GREEDY: rightmost point pick karo
            }                                 // (max future windows cover honge)
        }
        return true;
    }

public:
    int minStable(vector<int>& nums, int maxC) {
        n = nums.size();
        SegmentTree seg(nums);

        int left = 0, right = n;
        int ans = n;                          // fallback: L = n hamesha possible hai

        // is_possible(L) monotone hai: L bada → aur aasan
        // → sabse chhota L dhoondho jahan true ho
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (is_possible(seg, maxC, mid)) {
                ans = mid;
                right = mid - 1;              // aur chhota try karo
            } else {
                left = mid + 1;               // itna kaafi nahi
            }
        }

        return ans;
    }
};