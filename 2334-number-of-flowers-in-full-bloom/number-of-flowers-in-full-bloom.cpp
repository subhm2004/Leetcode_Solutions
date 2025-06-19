#define MAX_RANGE 1e9
class SegmentTree {
private:
    struct Node {
        int val = 0, lazy = 0;
        Node *left = nullptr, *right = nullptr;
    };

    Node* root;

    void push(Node* node, int l, int r) {
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();

        if (node->lazy != 0) {
            node->val += node->lazy;
            if (l != r) {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }
    }

    void update(Node* node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            node->lazy += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node->left, l, mid, ql, qr, val);
        update(node->right, mid + 1, r, ql, qr, val);
        node->val = node->left->val + node->right->val;
    }

    int query(Node* node, int l, int r, int pos) {
        push(node, l, r);
        if (l == r) return node->val;
        int mid = (l + r) / 2;
        if (pos <= mid) return query(node->left, l, mid, pos);
        else return query(node->right, mid + 1, r, pos);
    }

public:
    SegmentTree() {
        root = new Node();
    }

    void update(int l, int r, int val) {
        update(root, 0, MAX_RANGE, l, r, val);
    }

    int query(int pos) {
        return query(root, 0, MAX_RANGE, pos);
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        set<int> coordinates;

        // Collect all times
        for (auto& f : flowers) {
            coordinates.insert(f[0]);
            coordinates.insert(f[1]);
        }
        for (int t : people) coordinates.insert(t);

        // Compress coordinates
        unordered_map<int, int> compress;
        int idx = 0;
        for (int x : coordinates) {
            compress[x] = idx++;
        }

        SegmentTree seg;

        // Range update for each flower [start, end]
        for (auto& f : flowers) {
            int l = compress[f[0]];
            int r = compress[f[1]];
            seg.update(l, r, 1);
        }

        // Point query for each person
        vector<int> ans;
        for (int t : people) {
            int pos = compress[t];
            ans.push_back(seg.query(pos));
        }

        return ans;
    }
};
