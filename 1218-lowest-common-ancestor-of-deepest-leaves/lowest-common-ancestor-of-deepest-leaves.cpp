struct T {
    TreeNode* lca; // Lowest Common Ancestor store karega
    int depth;     // Deepest node ka depth store karega
};

class Solution {
public:
    T findDeepest(TreeNode* root) {
        if (!root)
            return {nullptr, 0}; // Base case: agar node NULL ho toh

        T left = findDeepest(root->left);  // Left subtree ka LCA aur depth find karo
        T right = findDeepest(root->right); // Right subtree ka LCA aur depth find karo

        if (left.depth > right.depth) { 
            return {left.lca, left.depth + 1}; // Left subtree jyada deep hai, toh wahi answer hoga
        } else if (left.depth < right.depth) {
            return {right.lca, right.depth + 1}; // Right subtree jyada deep hai, toh wahi answer hoga
        } else {
            return {root, left.depth + 1}; // Dono depth same hai, toh current node hi LCA hoga
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
        return findDeepest(root).lca; // Root se start karke LCA find karo
    }
};
