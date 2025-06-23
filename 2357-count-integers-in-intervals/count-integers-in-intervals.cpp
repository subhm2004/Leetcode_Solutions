#define MAX_RANGE 1e9

class SegmentTree {
private:
    struct Node {
        int val = 0;
        int lazy = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    
    Node* root;
    
    void push(Node* node, int low, int high) {
        if (!node || !node->lazy) return;
        
        node->val = high - low + 1;
        if (low != high) {
            if (!node->left) {
                node->left = new Node();
                node->right = new Node();
            }
            node->left->lazy = true;
            node->right->lazy = true;
        }
        node->lazy = false;
    }
    
    void update(Node*& node, int low, int high, int ql, int qr) {
        // Create node if it doesn't exist
        if (!node) node = new Node();
        
        // No overlap case
        if (high < ql || qr < low) return;
        
        // Apply lazy propagation
        push(node, low, high);
        
        // If current range is already fully covered, return
        if (node->val == high - low + 1) return;
        
        // Complete overlap case
        if (low >= ql && high <= qr) {
            node->lazy = true;
            push(node, low, high);
            return;
        }
        
        // Create child nodes for partial overlap
        if (!node->left) {
            node->left = new Node();
            node->right = new Node();
        }
        
        // Partial overlap case
        int mid = low + (high - low) / 2;
        update(node->left, low, mid, ql, qr);
        update(node->right, mid + 1, high, ql, qr);
        
        // Update current node value from children
        node->val = node->left->val + node->right->val;
    }
    
public:
    SegmentTree() {
        root = new Node();
    }
    
    void update(int l, int r) {
        update(root, 0, MAX_RANGE, l, r);
    }
    
    int getCount() {
        return root->val;
    }
};

class CountIntervals {
private:
    SegmentTree seg;
    
public:
    CountIntervals() {}
    
    void add(int l, int r) {
        seg.update(l, r);
    }
    
    int count() {
        return seg.getCount();
    }
};