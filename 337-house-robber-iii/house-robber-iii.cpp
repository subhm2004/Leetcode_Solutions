
class Solution {
public:
    int solveRE(TreeNode* root) {
        if (!root)
            return 0;
        int include = 0, exclude = 0;
        // ROB
        include += root->val;
        if (root->left) {
            include += solveRE(root->left->left) + solveRE(root->left->right);
        }
        if (root->right) {
            include += solveRE(root->right->left) + solveRE(root->right->right);
        }

        // DON'T ROB
        exclude = solveRE(root->left) + solveRE(root->right);
        return max(include, exclude);
    }
    int solveME(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (!root)
            return 0;
        if (dp.find(root) != dp.end())
            return dp[root];
        int include = 0, exclude = 0;
        // ROB
        include += root->val;
        if (root->left) {
            include +=
                solveME(root->left->left, dp) + solveME(root->left->right, dp);
        }
        if (root->right) {
            include += solveME(root->right->left, dp) +
                       solveME(root->right->right, dp);
        }

        // DON'T ROB
        exclude = solveME(root->left, dp) + solveME(root->right, dp);
        return dp[root] = max(include, exclude);
    }
    int rob(TreeNode* root) {
        // return solveRE(root);
        unordered_map<TreeNode*, int> dp;
        return solveME(root, dp);
    }
};