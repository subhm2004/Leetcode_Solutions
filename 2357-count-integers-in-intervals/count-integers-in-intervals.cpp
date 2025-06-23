#define MAX_RANGE 1e9

class SegmentTree {
private:
    struct Node {
        int val = 0;
        int lazy = false;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;

    void push(Node* node, int l, int r) {
        if (!node || !node->lazy)
            return;
        if (node->lazy != 0) {

            node->val = r - l + 1;

            if (l != r) {
                if (!node->left)
                    node->left = new Node();
                if (!node->right)
                    node->right = new Node();

                node->left->lazy = true;
                node->right->lazy = true;
            }

            node->lazy = false;
        }
    }

    void update(Node*& node, int l, int r, int ql, int qr) {
        // Create node if it doesn't exist
        if (!node)
            node = new Node();

        // No overlap case
        if (r < ql || qr < l)
            return;

        // Apply lazy propagation
        push(node, l, r);

        // If current range is already fully covered, return
        if (node->val == r - l + 1)
            return;

        // Complete overlap case
        if (l >= ql && r <= qr) {
            node->lazy = true;
            push(node, l, r);
            return;
        }

        // Create child nodes for partial overlap
        if (!node->left) {
            node->left = new Node();
            node->right = new Node();
        }

        // Partial overlap case
        int mid = l + (r - l) / 2;
        update(node->left, l, mid, ql, qr);
        update(node->right, mid + 1, r, ql, qr);

        // Update current node value from children
        node->val = node->left->val + node->right->val;
    }

public:
    SegmentTree() { root = new Node(); }

    void update(int l, int r) { update(root, 0, MAX_RANGE, l, r); }

    int get_Count() { return root->val; }
};

class CountIntervals {
private:
    SegmentTree seg;

public:
    CountIntervals() {}

    void add(int l, int r) { seg.update(l, r); }

    int count() { return seg.get_Count(); }
};