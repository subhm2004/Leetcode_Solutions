class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: null node
        if (root == nullptr) return false;

        // If it's a leaf node, check if the value matches the remaining target
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        // Recursively check left and right subtrees with reduced target
        int remaining_Sum = targetSum - root->val;
        return hasPathSum(root->left, remaining_Sum) || hasPathSum(root->right, remaining_Sum);
    }
};
