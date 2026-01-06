#define MAX_RANGE 1e9
class SegmentTree {
private:
    struct Node {
        long val = 0;
        long lazy = 0;
        Node* left = nullptr;
        Node* right = nullptr;
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
        node->val = max(node->left->val, node->right->val);
    }

    long query(Node* node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return node->val;

        int mid = (l + r) / 2;
        return max(
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

    long query(int l, int r) {
        return query(root, 0, MAX_RANGE, l, r);
    }
};

class MyCalendarThree {
    SegmentTree seg;

public:
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        seg.update(startTime, endTime - 1, 1);             // Add the booking
        return seg.query(0, MAX_RANGE);                          // Return max k-booking
    }
};
