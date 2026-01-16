class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string,int> freq;

    string dfs(TreeNode* root) {
        if (!root) return "null";   // null marker

        // PREORDER serialization
        string key = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);

        if (freq[key] == 1) {
            ans.push_back(root);   // duplicate subtree found
        }

        freq[key]++;
        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
