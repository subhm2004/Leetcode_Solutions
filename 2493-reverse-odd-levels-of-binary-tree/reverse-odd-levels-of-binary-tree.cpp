class Solution {
public:
    void dfs(TreeNode* left, TreeNode* right, bool is_odd_level) {
        if (left == nullptr)
            return;
        if (is_odd_level)
            swap(left->val, right->val);
        dfs(left->left, right->right, !is_odd_level);
        dfs(left->right, right->left, !is_odd_level);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
};