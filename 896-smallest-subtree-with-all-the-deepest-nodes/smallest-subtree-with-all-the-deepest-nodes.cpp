struct Result {
    TreeNode* lca;
    int depth;
};

class LCAFinder {
public:
    Result findLCA(TreeNode* root) {
        if (!root)
            return {nullptr, 0}; // Base Case

        Result left = findLCA(root->left);
        Result right = findLCA(root->right);

        if (left.depth > right.depth)
            return {left.lca, left.depth + 1}; // Left subtree is deeper

        if (right.depth > left.depth)
            return {right.lca, right.depth + 1}; // Right subtree is deeper

        return {root, left.depth + 1}; // Both sides equal, root is LCA
    }
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        LCAFinder solver;
        return solver.findLCA(root).lca;
    }
};
