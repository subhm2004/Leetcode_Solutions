class Solution {
public:
    int ans = 0;

    // ye function return krta hai subtree ki maximum value (post order traversal hai )
    int solve(TreeNode* root) {
        if (root == nullptr)
            return INT_MIN;

        int left_max = solve(root->left);
        int right_max = solve(root->right);

        int max_value_of_subtree = max({root->val, left_max, right_max});

        if (root->val == max_value_of_subtree)
            ans++;

        return max_value_of_subtree;
    }

    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};