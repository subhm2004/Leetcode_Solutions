class SegmentTree {
    struct Node {
        int max_Len;
        char left_Char;
        int left_Len;
        char right_Char;
        int right_Len;
        int l, r;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& left, const Node& right) {
        Node ans;
        ans.l = left.l;
        ans.r = right.r;
        ans.left_Char = left.left_Char;
        ans.right_Char = right.right_Char;

        ans.left_Len = left.left_Len;
        if (left.left_Len == (left.r - left.l + 1) && left.right_Char == right.left_Char) {
            ans.left_Len += right.left_Len;
        }

        ans.right_Len = right.right_Len;
        if (right.right_Len == (right.r - right.l + 1) && right.left_Char == left.right_Char) {
            ans.right_Len += left.right_Len;
        }

        ans.max_Len = max(left.max_Len, right.max_Len);
        if (left.right_Char == right.left_Char) {
            ans.max_Len = max(ans.max_Len, left.right_Len + right.left_Len);
        }

        return ans;
    }

    void build(const string& s, int node, int l, int r) {
        if (l == r) {
            segTree[node] = {1, s[l], 1, s[l], 1, l, r};
            return;
        }
        int mid = (l + r) / 2;
        build(s, 2 * node + 1, l, mid);
        build(s, 2 * node + 2, mid + 1, r);
        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    void update(int node, int l, int r, int idx, char val) {
        if (l == r) {
            segTree[node] = {1, val, 1, val, 1, l, r};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);

        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        segTree.resize(4 * n);
        build(s, 0, 0, n - 1);
    }

    void update(int idx, char val) {
        update(0, 0, n - 1, idx, val);
    }

    int get_Max_Len() {
        return segTree[0].max_Len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree seg(s);
        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); ++i) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];
            seg.update(idx, ch);
            ans.push_back(seg.get_Max_Len());
        }

        return ans;
    }
};
