class Solution {
public:
    void dfs(TreeNode* root, int level, long index, vector<long>& startOfLevel,
             long& ans) {
        if (!root)
            return;

        if (level >= startOfLevel.size())
            startOfLevel.push_back(index);

        // Normalize index to prevent overflow
        ans = max(ans, index - startOfLevel[level] + 1);

        // Left child -> (index - startOfLevel[level]) * 2
        // Right child -> (index - startOfLevel[level]) * 2 + 1
        long newIndex = index - startOfLevel[level];
        dfs(root->left, level + 1, newIndex * 2, startOfLevel, ans);
        dfs(root->right, level + 1, newIndex * 2 + 1, startOfLevel, ans);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<long> startOfLevel;
        long ans = 0;
        dfs(root, 0, 0, startOfLevel, ans); // Start index from 0
        return ans;
    }
};
