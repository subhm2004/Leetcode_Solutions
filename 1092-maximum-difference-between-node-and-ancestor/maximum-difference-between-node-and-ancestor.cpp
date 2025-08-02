class Solution {
public:
    int max_diff_function(TreeNode* node, int mini_val, int maxi_val) {
        if (!node)
            return maxi_val - mini_val;

        mini_val = min(mini_val, node->val);
        maxi_val = max(maxi_val, node->val);

        int leftDiff = max_diff_function(node->left, mini_val, maxi_val);
        int rightDiff = max_diff_function(node->right, mini_val, maxi_val);

        return max(leftDiff, rightDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        return max_diff_function(root, root->val, root->val);
    }
};
