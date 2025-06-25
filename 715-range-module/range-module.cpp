#define MAX_RANGE 1e9

class SegmentTree {
private:
    struct Node {
        int l, r;
        bool state;
        Node* left = nullptr;
        Node* right = nullptr;

    };

    Node* root;

    void push(Node* node) {
        if (!node || node->l + 1 == node->r || node->left != nullptr)
            return;

        int mid = node->l + (node->r - node->l) / 2;
        node->left = new Node(node->l, mid, node->state);
        node->right = new Node(mid, node->r, node->state);
    }

    bool update(Node* node, int ql, int qr, bool value) {
        if (!node || qr <= node->l || ql >= node->r)
            return node ? node->state : false;

        if (ql <= node->l && node->r <= qr) {
            node->state = value;
            node->left = node->right = nullptr;
            return value;
        }

        push(node);

        bool leftState = update(node->left, ql, qr, value);
        bool rightState = update(node->right, ql, qr, value);
        node->state = leftState && rightState;
        return node->state;
    }

    bool query(Node* node, int ql, int qr) {
        if (!node || qr <= node->l || ql >= node->r)
            return true;

        if ((ql <= node->l && node->r <= qr) || (node->left == nullptr && node->right == nullptr))
            return node->state;

        return query(node->left, ql, qr) && query(node->right, ql, qr);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    SegmentTree() {
        root = new Node(0, MAX_RANGE, false);
    }

    ~SegmentTree() {
        destroy(root);
    }

    void set_Range(int l, int r) {
        update(root, l, r, true);
    }

    void unset_Range(int l, int r) {
        update(root, l, r, false);
    }

    bool is_Range_Set(int l, int r) {
        return query(root, l, r);
    }
};
class RangeModule {
private:
    SegmentTree seg;

public:
    RangeModule() {}

    void addRange(int left, int right) {
        seg.set_Range(left, right);
    }

    void removeRange(int left, int right) {
        seg.unset_Range(left, right);
    }

    bool queryRange(int left, int right) {
        return seg.is_Range_Set(left, right);
    }
};
