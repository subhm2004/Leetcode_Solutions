class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max((height(root->left)), (height(root->right))) + 1;
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};