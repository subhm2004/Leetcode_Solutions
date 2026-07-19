class Solution {
public:
    unordered_map<int, int> mp;
    int max_freq = 0;

    // POSTORDER
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        int sum = root->val + leftSum + rightSum;

        mp[sum]++;
        max_freq = max(max_freq, mp[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;

        for (auto &it : mp) {
            if (it.second == max_freq)
                ans.push_back(it.first);
        }

        return ans;
    }
};