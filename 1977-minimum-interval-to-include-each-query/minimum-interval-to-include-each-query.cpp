#define MAX_RANGE 1e7
class SegmentTree {
private:
    struct Node {
        int val = INT_MAX, lazy = INT_MAX;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;

    void push(Node* node, int l, int r) {
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();

        if (node->lazy != INT_MAX) {
            node->val = min(node->val, node->lazy);
            if (l != r) {
                node->left->lazy = min(node->left->lazy, node->lazy);
                node->right->lazy = min(node->right->lazy, node->lazy);
            }
            node->lazy = INT_MAX;
        }
    }

    void update(Node* node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            node->lazy = val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node->left, l, mid, ql, qr, val);
        update(node->right, mid + 1, r, ql, qr, val);
        node->val = min(node->left->val, node->right->val);
    }

    int query(Node* node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return INT_MAX;
        if (ql <= l && r <= qr) return node->val;

        int mid = (l + r) / 2;
        return min(
            query(node->left, l, mid, ql, qr),
            query(node->right, mid + 1, r, ql, qr)
        );
    }

public:
    SegmentTree() {
        root = new Node();
    }

    void update(int l, int r, int val) {
        update(root, 0, MAX_RANGE, l, r, val);
    }

    int query(int l, int r) {
        return query(root, 0, MAX_RANGE, l, r);
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Step 1: Coordinate compression
        set<int> coords;
        for (auto& it : intervals) {
            coords.insert(it[0]);
            coords.insert(it[1]);
        }
        for (int q : queries) coords.insert(q);

        unordered_map<int, int> compress;
        int idx = 0;
        for (int x : coords) compress[x] = idx++;

        SegmentTree seg;

        // Step 2: Update intervals with compressed coordinates
        for (auto& it : intervals) {
            int l = compress[it[0]];
            int r = compress[it[1]];
            int size = it[1] - it[0] + 1;
            seg.update(l, r, size);
        }

        // Step 3: Query on compressed coordinates
        vector<int> ans;
        for (int q : queries) {
            int cq = compress[q];
            int res = seg.query(cq, cq);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};

