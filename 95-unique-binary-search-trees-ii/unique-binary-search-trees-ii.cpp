class Solution {
public:
    vector<TreeNode*> allcomb(int start, int end) {
        if (start > end)
            return {0};
        if (start == end)
            return {new TreeNode(end)};
        vector<TreeNode*> ans;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = allcomb(start, i - 1);
            vector<TreeNode*> right = allcomb(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return allcomb(1, n);
    }
};
