class Solution {
public:
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ans_level = 1;
        long long max_sum = LLONG_MIN;

        while (!q.empty()) {
            int sz = q.size();
            long long level_sum = 0;

            // current level process karo
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // max sum update
            if (level_sum > max_sum) {
                max_sum = level_sum;
                ans_level = level;
            }

            level++;
        }

        return ans_level;
    }

    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
};
