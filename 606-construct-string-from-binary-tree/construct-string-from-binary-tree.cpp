class Solution {
 public:
  string tree2str(TreeNode* root) {
    if (!root) return "";  // Base case: if tree is empty, return empty string.

    string result = to_string(root->val);  // Convert root value to string.

    if (root->left || root->right) {  
      result += "(" + tree2str(root->left) + ")";  // Always add left child.
    }
    if (root->right) {  
      result += "(" + tree2str(root->right) + ")";  // Add right child only if it exists.
    }

    return result;
  }
};
