class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: Agar root NULL ho ya phir p ya q me se koi root ho, toh wahi LCA hoga
        if (root == p || root == q || root == NULL) return root;

        // Recursively left aur right subtree me LCA dhundh rahe hain
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Agar dono taraf se non-null value mili, iska matlab p aur q dono alag-alag side hain
        // Toh yeh current node hi unka LCA hoga
        if (left != NULL && right != NULL) return root;

        // Agar sirf left me value mili, toh left ka result return karo
        else if (left != NULL) return left;

        // Agar sirf right me value mili, toh right ka result return karo
        else if (right != NULL) return right;

        // Agar dono NULL hain toh return NULL
        return NULL;
    }
};
