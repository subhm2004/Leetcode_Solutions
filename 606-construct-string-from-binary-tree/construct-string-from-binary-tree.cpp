class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return ""; // Base case: if tree is empty, return empty string.

        string ans = to_string(root->val); // Convert root value to string.

        // Case 1: left child exists OR right child exists
        if (root->left || root->right) {
            ans += "(" + tree2str(root->left) + ")"; // Always add left child.
        }

        // Case 2: right child exists
        if (root->right) {
            ans += "(" + tree2str(root->right) + ")"; // Add right child only if it exists.
        }

        return ans;
    }
};
