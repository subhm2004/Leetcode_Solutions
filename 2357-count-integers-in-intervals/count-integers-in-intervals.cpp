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
    
    void update(Node*& node, int low, int high, int l, int r) {
        // Create node if it doesn't exist
        if (!node) node = new Node();
        
        // No overlap case
        if (high < l || r < low) return;
        
        // Create child nodes if they don't exist
        if (!node->left) {
            node->left = new Node();
            node->right = new Node();
        }
        
        // Apply lazy propagation
        if (node->lazy) {
            node->val = high - low + 1;
            if (low != high) {
                node->left->lazy = 1;
                node->right->lazy = 1;
            }
            node->lazy = 0;
        }
        
        // If current range is already fully covered, return
        if (node->val == high - low + 1) return;
        
        // Complete overlap case
        if (low >= l && high <= r) {
            node->val = high - low + 1;
            if (low != high) {
                node->left->lazy = 1;
                node->right->lazy = 1;
            }
            node->lazy = 0;
            return;
        }
        
        // Partial overlap case
        int mid = low + (high - low) / 2;
        update(node->left, low, mid, l, r);
        update(node->right, mid + 1, high, l, r);
        
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
    
    void add(int left, int right) {
        seg.update(left, right);
    }
    
    int count() {
        return seg.getCount();
    }
};