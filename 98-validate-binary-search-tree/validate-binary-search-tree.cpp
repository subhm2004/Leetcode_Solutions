using ll = long long;
class Solution {
public:
    bool helper(TreeNode* root, ll min, ll max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) {
            return false;
        }

        return helper(root->left, min, root->val) &&
               helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
//