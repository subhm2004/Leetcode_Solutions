class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, unordered_map<int,int>& freq) {
        if (!node) return;

        freq[node->val]++; // include current node

        // leaf node
        if (!node->left && !node->right) {
            int odd = 0;
            for (auto &p : freq) {
                if (p.second % 2 == 1) odd++;
            }
            if (odd <= 1) ans++;
        }

        dfs(node->left, freq);
        dfs(node->right, freq);

        freq[node->val]--; // backtrack
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int,int> freq;
        dfs(root, freq);
        return ans;
    }
};
