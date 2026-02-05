using ll = long long;
class SegmentTree {
private:
    vector<ll> segTree;
    int n;

    void build(const vector<int>& arr, int i, int l, int r) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
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
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    ll query_Range(int i, int l, int r, int start, int end) {
        if (r < start || l > end)
            return 0;
        if (start <= l && r <= end)
            return segTree[i];
        int mid = (l + r) / 2;
        return query_Range(2 * i + 1, l, mid, start, end) +
               query_Range(2 * i + 2, mid + 1, r, start, end);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    void update_Point(int idx, int val) { update_Point(0, 0, n - 1, idx, val); }
    ll query_Range(int l, int r) { return query_Range(0, 0, n - 1, l, r); }
};
class Solution {
public:
    // checks if there is peak at index i 
    bool check_if_peak(int i, vector<int>& nums) {
        int n = nums.size();
        if (i <= 0 || i >= n - 1)
            return false;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // is_peak array
        vector<int> is_peak(n, 0);

        for (int i = 1; i < n - 1; i++)
            if (check_if_peak(i, nums))
                is_peak[i] = 1;

        SegmentTree st(is_peak);

        vector<int> ans;

        for (auto& q : queries) {
            // type 1 : range query
            if (q[0] == 1) {
                int l = q[1];
                int r = q[2];

                if (r - l + 1 < 3) {
                    ans.push_back(0);
                    continue;
                }

                ans.push_back((int)st.query_Range(l + 1, r - 1));
            }
            // type 2 : update
            else {
                int idx = q[1];
                int val = q[2];

                nums[idx] = val;

                // sirf idx-1, idx, idx+1 hi affect ho sakte hain
                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i <= 0 || i >= n - 1)
                        continue;

                    int new_val = check_if_peak(i, nums) ? 1 : 0;

                    if (is_peak[i] != new_val) {
                        is_peak[i] = new_val;
                        st.update_Point(i, new_val);
                    }
                }
            }
        }

        return ans;
    }
};