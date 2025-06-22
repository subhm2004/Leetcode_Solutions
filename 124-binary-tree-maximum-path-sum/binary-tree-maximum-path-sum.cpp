class Solution {
    int max_sum = INT_MIN;  // class-level variable
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        max_sum = max(max_sum, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};
