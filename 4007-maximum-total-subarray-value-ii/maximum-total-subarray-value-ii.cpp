class SegmentTree {
public:
    int n;
    vector<int> mini_seg;
    vector<int> maxi_seg;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        mini_seg.assign(4 * n, 0);
        maxi_seg.assign(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            mini_seg[i] = nums[l];
            maxi_seg[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, 2 * i + 1, l, mid);
        build(nums, 2 * i + 2, mid + 1, r);
        mini_seg[i] = min(mini_seg[2 * i + 1], mini_seg[2 * i + 2]);
        maxi_seg[i] = max(maxi_seg[2 * i + 1], maxi_seg[2 * i + 2]);
    }

    int min_query(int ql, int qr, int i, int l, int r) {
        if (r < ql || l > qr)
            return INT_MAX;
        if (ql <= l && r <= qr)
            return mini_seg[i];
        int mid = (l + r) / 2;
        return min(min_query(ql, qr, 2 * i + 1, l, mid), min_query(ql, qr, 2 * i + 2, mid + 1, r));
    }

    int max_query(int ql, int qr, int i, int l, int r) {
        if (r < ql || l > qr)
            return INT_MIN;
        if (ql <= l && r <= qr)
            return maxi_seg[i];
        int mid = (l + r) / 2;
        return max(max_query(ql, qr, 2 * i + 1, l, mid), max_query(ql, qr, 2 * i + 2, mid + 1, r));
    }

    int rangeMin(int l, int r) { return min_query(l, r, 0, 0, n - 1); }
    int rangeMax(int l, int r) { return max_query(l, r, 0, 0, n - 1); }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree seg(nums); // koi update nhi ho rhe hai 

        // Max heap: {value, {l, r}}
        priority_queue<pair<long long, pair<int, int>>> maxHeap;
        set<pair<int, int>> visited;

        long long start_val = seg.rangeMax(0, n - 1) - seg.rangeMin(0, n - 1);
        maxHeap.push({start_val, {0, n - 1}});
        visited.insert({0, n - 1});

        long long ans = 0;

        while (k-- > 0 && !maxHeap.empty()) {
            auto [val, range] = maxHeap.top();
            maxHeap.pop();

            int l = range.first;
            int r = range.second;

            ans += val;

            // Left se shrink → [l+1 .. r]
            if (l + 1 <= r && !visited.count({l + 1, r})) {
                long long v = seg.rangeMax(l + 1, r) - seg.rangeMin(l + 1, r);
                maxHeap.push({v, {l + 1, r}});
                visited.insert({l + 1, r});
            }

            // Right se shrink → [l .. r-1]
            if (l <= r - 1 && !visited.count({l, r - 1})) {
                long long v = seg.rangeMax(l, r - 1) - seg.rangeMin(l, r - 1);
                maxHeap.push({v, {l, r - 1}});
                visited.insert({l, r - 1});
            }
        }

        return ans;
    }
};