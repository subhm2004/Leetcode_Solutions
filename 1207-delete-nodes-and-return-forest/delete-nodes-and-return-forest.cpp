/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<int> to_delete_nodes;
    vector<TreeNode*> forest;

    TreeNode* dfs(TreeNode* node, bool is_root) {
        if (!node) return nullptr;

        bool deleted = to_delete_nodes.count(node->val);

        if (is_root && !deleted) {
            forest.push_back(node);
        }

        node->left = dfs(node->left, deleted);
        node->right = dfs(node->right, deleted);

        return deleted ? nullptr : node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        to_delete_nodes = unordered_set<int>(to_delete.begin(), to_delete.end());
        dfs(root, true);
        return forest;
    }
};
