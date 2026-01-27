class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base Case:
        // Agar root null ho ya root hi p/q ke barabar ho
        // toh wahi return karo — possible LCA ho sakta hai.
        if (!root || root == p || root == q) 
            return root;

        // Left subtree me recursively p/q ko search kar rahe hain
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Right subtree me bhi recursively p/q ko search kar rahe hain
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Agar left aur right dono non-null aaye,
        // iska matlab p aur q alag-alag side me mile.
        // Toh current root hi unka LCA hai.
        if (left && right) 
            return root;

        // Warna jo bhi side non-null ho, wahi return kar do.
        return left ? left : right;
    }
};