// SegmentTree_PointUpdate_RangeQuery
class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(vector<int>& arr, int i, int l, int r) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);

        segTree[i] = __gcd(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void update_Point(int i, int l, int r, int idx, int val) {
        if (l == r) {
            segTree[i] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update_Point(2 * i + 1, l, mid, idx, val);
        else
            update_Point(2 * i + 2, mid + 1, r, idx, val);

        segTree[i] = __gcd(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    int query_Range(int i, int l, int r, int start, int end) {
        if (r < start || l > end)
            return 0;

        if (start <= l && r <= end)
            return segTree[i];

        int mid = (l + r) / 2;

        return __gcd(query_Range(2 * i + 1, l, mid, start, end),
                     query_Range(2 * i + 2, mid + 1, r, start, end));
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update_Point(int idx, int val) { update_Point(0, 0, n - 1, idx, val); }

    int query_Range(int l, int r) { return query_Range(0, 0, n - 1, l, r); }
};

class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p,
                        vector<vector<int>>& queries) {

        int n = nums.size();
     /*
         TRANSFORMATION:

    Hume sirf un elements se matlab hai jo p se divisible hain.

    Isliye:
    arr[i] = nums[i]/p   agar divisible ho
    warna arr[i] = 0


    KYU?

    Kyuki hume aisi subsequence chahiye jiska GCD exactly p ho.

    Agar sab elements ko p se divide kar dein,
    toh problem convert ho jaati hai:

    "Kya koi aisi subsequence hai jiska GCD = 1 ho?"
         */
        vector<int> arr(n);
        int divisible_count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % p == 0) {
                arr[i] = nums[i] / p;
                divisible_count++;
            } else {
                arr[i] = 0;
            }
        }

        SegmentTree seg(arr);

        int ans = 0;

        for (auto q : queries) {
            int idx = q[0];
            int val = q[1];

            if (nums[idx] % p == 0) divisible_count--;
            nums[idx] = val;

            if (val % p == 0) {
                divisible_count++;
                seg.update_Point(idx, val / p);
            } else {
                seg.update_Point(idx, 0);
            }

            int gcd_of_arr = seg.query_Range(0, n - 1);

            if (gcd_of_arr == 1) {
                if (divisible_count < n) {
                    // CASE A: saare divisible elements lo → length < n ✓
                    ans++;
                } else {
                    // CASE B: divisible_count == n
                    // Ek ek element chhodke check karo
                    bool found = false;
                    for (int i = 0; i < n && !found; i++) {
                        int left_gcd  = (i > 0)   ? seg.query_Range(0, i - 1) : 0;
                        int right_gcd = (i < n-1) ? seg.query_Range(i + 1, n - 1) : 0;
                        int total_gcd_after_excluding_one_element = __gcd(left_gcd, right_gcd);
                        if (total_gcd_after_excluding_one_element == 1) found = true;
                    }
                    if (found) ans++;
                }
            }
        }

        return ans;
    }
};