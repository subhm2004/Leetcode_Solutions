class SegmentTree {
private:

    vector<int> segTree;
    int n;

    void build(const vector<int> &arr, int i, int l, int r) {

        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    // Range Sum Query
    int query_Range(int i, int l, int r, int start, int end) {

        // No Overlap
        if (r < start || l > end)
            return 0;

        // Complete Overlap
        if (start <= l && r <= end)
            return segTree[i];

        // Partial Overlap
        int mid = (l + r) / 2;

        return query_Range(2 * i + 1, l, mid, start, end) +
               query_Range(2 * i + 2, mid + 1, r, start, end);
    }

public:

    SegmentTree(const vector<int> &arr) {

        n = arr.size();

        segTree.resize(4 * max(1, n));

        if (n > 0)
            build(arr, 0, 0, n - 1);
    }

    int query_Range(int l, int r) {

        return query_Range(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        int n = s.size();

        // '*' -> 1, '|' -> 0
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                arr[i] = 1;
            else
                arr[i] = 0;
        }

        SegmentTree st(arr);

        vector<int> leftCandle(n);
        vector<int> rightCandle(n);

        // Nearest candle on left
        int last = -1;
        for (int i = 0; i < n; i++) {

            if (s[i] == '|')
                last = i;

            leftCandle[i] = last;
        }

        // Nearest candle on right
        last = -1;
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '|')
                last = i;

            rightCandle[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int left = rightCandle[q[0]];
            int right = leftCandle[q[1]];

            if (left == -1 || right == -1 || left >= right) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.query_Range(left, right));
            }
        }

        return ans;
    }
};