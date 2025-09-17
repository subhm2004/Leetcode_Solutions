class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // DFS helper function banayenge
        // Return karega:
        // true  -> agar node bachi (sufficient h)
        // false -> agar node delete karni h (insufficient h)
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int sum) {
            if (!node) return false;       // agar node hi null h to delete samjho

            sum += node->val;             // current node ka value add kar diya path sum me

            // Case 1: Agar node leaf h (koi children nahi)
            if (!node->left && !node->right) {
                // Agar path sum limit se bada ya equal h -> keep node
                // Nahi to delete karna h -> return false
                return sum >= limit;
            }

            // Case 2: Non-leaf node h, to left aur right subtree check karenge
            bool left_sub_tree = dfs(node->left, sum);   // left subtree sufficient h ya nahi
            bool right_sub_tree = dfs(node->right, sum); // right subtree sufficient h ya nahi

            // Agar left subtree insufficient h to usko null kar do
            if (!left_sub_tree) node->left = nullptr;

            // Agar right subtree insufficient h to usko null kar do
            if (!right_sub_tree) node->right = nullptr;

            // Agar dono side se koi bhi sufficient path nahi mila
            // to current node bhi insufficient h -> return false
            return left_sub_tree || right_sub_tree;
        };

        // Root se DFS start karenge, initial sum = 0
        // Agar root bhi insufficient h to nullptr return karna h
        return dfs(root, 0) ? root : nullptr;
    }
};
