typedef long long ll;
class Solution {
public:
    bool isValidBSTHelper(TreeNode* root,ll min, ll max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return isValidBSTHelper(root->left, min, root->val) &&
               isValidBSTHelper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {

        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};
// 