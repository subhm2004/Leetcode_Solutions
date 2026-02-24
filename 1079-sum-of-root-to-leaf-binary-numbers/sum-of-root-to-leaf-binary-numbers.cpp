class Solution {
public:
    int solve(TreeNode* node, int curr_sum) {
        if (!node)
            return 0;

        curr_sum = (curr_sum * 2) + node->val;

        if (!node->left && !node->right)
            return curr_sum;

        return solve(node->left, curr_sum) + solve(node->right, curr_sum);
    }
    int sumRootToLeaf(TreeNode* root) { return solve(root, 0); }
};
