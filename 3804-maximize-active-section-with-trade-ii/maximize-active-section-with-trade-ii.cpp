class SegmentTree {
public:
    vector<int> segTree;
    int n;

    SegmentTree(vector<int> &arr) {
        n = arr.size();

        if (n == 0) return;

        segTree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int l, int r, vector<int> &arr) {
        if (l == r) {
            segTree[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);

        segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return INT_MIN;

        if (ql <= l && r <= qr)
            return segTree[node];

        int mid = l + (r - l) / 2;

        return max(query(2 * node + 1, l, mid, ql, qr),
                   query(2 * node + 2, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        if (n == 0 || l > r)
            return INT_MIN;

        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.size();

        int active_count = count(s.begin(), s.end(), '1');

        vector<int> block_Start, block_End;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                block_Start.push_back(start);
                block_End.push_back(i - 1);
            } else {
                i++;
            }
        }

        int m = block_Start.size();

        if (m < 2)
            return vector<int>(queries.size(), active_count);

        vector<int> block_size(m);

        for (int i = 0; i < m; i++)
            block_size[i] = block_End[i] - block_Start[i] + 1;

        vector<int> pair_sum;

        for (int i = 0; i + 1 < m; i++)
            pair_sum.push_back(block_size[i] + block_size[i + 1]);

        SegmentTree seg(pair_sum);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int low = lower_bound(block_End.begin(), block_End.end(), l) - block_End.begin();

            int high = upper_bound(block_Start.begin(), block_Start.end(), r) - block_Start.begin() - 1;

            int max_pair_sum = 0;

            if (low < high) {

                int first_len = block_End[low] - max(block_Start[low], l) + 1;

                int last_len =  min(block_End[high], r) - block_Start[high] + 1;

                if (high - low == 1) {

                    max_pair_sum = first_len + last_len;

                } else {

                    int pair1 = first_len + block_size[low + 1];

                    int pair2 = block_size[high - 1] + last_len;

                    int pair3 = seg.query(low + 1, high - 2);

                    max_pair_sum = max({pair1, pair2, pair3});
                }
            }

            ans.push_back(active_count + max_pair_sum);
        }

        return ans;
    }
};