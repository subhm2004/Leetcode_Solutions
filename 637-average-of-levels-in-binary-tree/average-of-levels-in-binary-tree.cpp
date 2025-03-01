class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back((double)sum / size);  // Average of current level
        }

        return result;
    }
};
