class Solution {
public:
    long long total_sum = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    // Total sum of tree
    long long calculate_sum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + calculate_sum(root->left) + calculate_sum(root->right);
    }

    // DFS to compute subtree sums & max product
    long long dfs(TreeNode* root) {
        if (!root)
            return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subtree_sum = root->val + left + right;

        ans = max(ans, subtree_sum * (total_sum - subtree_sum));

        return subtree_sum;
    }

    int maxProduct(TreeNode* root) {
        total_sum = calculate_sum(root);
        dfs(root);
        return ans % MOD;
    }
};
