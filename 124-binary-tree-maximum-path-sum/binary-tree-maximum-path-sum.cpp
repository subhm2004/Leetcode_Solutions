// https://www.youtube.com/watch?v=Op6YFcs8R9M
class Solution {
public:
    int max_sum = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int neeche_hi_milgaya_answer = left + right + root->val; //(1)

        int koi_ek_acha = max(left, right) + root->val; //(2)

        int only_root_acha = root->val; //(3)

        max_sum = max({max_sum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        // most important part
        return max(koi_ek_acha, only_root_acha);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return max_sum;
    }
};