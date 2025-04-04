struct T {
    TreeNode* lca; // Deepest nodes ka Lowest Common Ancestor store karega
    int depth;     // Deepest node ka depth store karega
};

class LCAFinder {
public:
    T findLCA(TreeNode* root) {
        if (!root)
            return {nullptr, 0}; // Base case: agar node NULL ho toh

        T left = findLCA(root->left);   // Left subtree ka LCA aur depth find karo
        T right = findLCA(root->right); // Right subtree ka LCA aur depth find karo

        if (left.depth > right.depth)
            return {left.lca, left.depth + 1}; // Left subtree jyada deep hai, toh wahi answer hoga

        if (right.depth > left.depth)
            return {right.lca, right.depth + 1}; // Right subtree jyada deep hai, toh wahi answer hoga

        return {root, left.depth + 1}; // Dono depth same hai, toh current node hi LCA hoga
    }
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        LCAFinder solver; // LCAFinder ka object banaya
        return solver.findLCA(root).lca; // Root se LCA find karke return karo
    }
};
