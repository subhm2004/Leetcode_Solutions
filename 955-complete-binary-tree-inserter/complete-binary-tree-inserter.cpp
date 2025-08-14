/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root;
    int total_nodes;

     int count_nodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + count_nodes(node->left) + count_nodes(node->right);
    }

    CBTInserter(TreeNode* r) {
        root = r;
        total_nodes = count_nodes(root);
    }
    
    TreeNode* insertRE(TreeNode* node, int idx, int pos, int v, int& parent_val) {
        if (!node) return nullptr;
        if (pos * 2 + 1 == idx) { // left child position 
            node->left = new TreeNode(v);
            parent_val = node->val;
        } else if (pos * 2 + 2 == idx) { // right child position  
            node->right = new TreeNode(v);
            parent_val = node->val;
        } else {
            insertRE(node->left, idx, pos * 2 + 1, v, parent_val);
            insertRE(node->right, idx, pos * 2 + 2, v, parent_val);
        }
        return node;
    }

    int insert(int v) {
        total_nodes++;
        int parent_val = -1;
        insertRE(root, total_nodes - 1, 0, v, parent_val);
        return parent_val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */