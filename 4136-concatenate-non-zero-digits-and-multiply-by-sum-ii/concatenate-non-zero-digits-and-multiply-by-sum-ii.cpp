struct Node {
    long long value;
    long long sum;
    int length;
};

class SegmentTree {
public:
    static const int MOD = 1e9 + 7;

    vector<Node> segTree;
    vector<long long> power_10;

    void build(int idx, int l, int r, string& s) {

        if (l == r) {

            if (s[l] == '0') {
                segTree[idx] = {0, 0, 0};
            } else {
                int digit = s[l] - '0';
                segTree[idx] = {digit, digit, 1};
            }

            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);

        segTree[idx] = merge(segTree[idx * 2], segTree[idx * 2 + 1]);
    }

    Node merge(Node left, Node right) {
        Node ans;

        ans.length = left.length + right.length;
        ans.sum = left.sum + right.sum;

        ans.value = (left.value * power_10[right.length]) % MOD;
        ans.value = (ans.value + right.value) % MOD;

        return ans;
    }

    SegmentTree(string& s) {
        int n = s.size();

        segTree.resize(4 * n + 1);

        power_10.resize(n + 1);

        power_10[0] = 1;

        for (int i = 1; i <= n; i++) {
            power_10[i] = (power_10[i - 1] * 10LL) % MOD;
        }

        build(1, 0, n - 1, s);
    }

    Node query(int idx, int l, int r, int ql, int qr) {

        if (r < ql || l > qr)
            return {0, 0, 0};

        if (ql <= l && r <= qr)
            return segTree[idx];

        int mid = (l + r) / 2;

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    Node get_Query(int l, int r, int n) { return query(1, 0, n - 1, l, r); }
};

class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        SegmentTree segment_tree(s);

        vector<int> ans;

        for (auto& q : queries) {

            auto cur = segment_tree.get_Query(q[0], q[1], n);

            ans.push_back((cur.value * cur.sum) % MOD);
        }

        return ans;
    }
};