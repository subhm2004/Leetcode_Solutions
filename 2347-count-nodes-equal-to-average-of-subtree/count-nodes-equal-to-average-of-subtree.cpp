class Solution {
public:
     pair<int, int> calculate_average(TreeNode* node, int& ans) {
        if (node == nullptr) return {0, 0};

        auto [left_sum, ledt_count] = calculate_average(node->left, ans);
        auto [right_sum, right_count] = calculate_average(node->right, ans);

        int sum = node->val + left_sum + right_sum;
        int count = 1 + ledt_count + right_count;

        if (sum / count == node->val) {
            ans++;
        }

        return {sum, count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        calculate_average(root, ans);
        return ans;
    }
};
