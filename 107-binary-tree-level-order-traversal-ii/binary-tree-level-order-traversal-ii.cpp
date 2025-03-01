// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> result;
//         if (root == NULL) {
//             return result;
//         }

//         int h = height(root);
//         for (int i = h; i >= 1; i--) {
//             vector<int> level;
//             printGivenLevel(root, i, level);
//             result.push_back(level);
//         }

//         return result;
//     }

//     int height(TreeNode* node) {
//         if (!node)
//             return 0;

//         int leftHeight = height(node->left);
//         int rightHeight = height(node->right);

//         return max(leftHeight, rightHeight) + 1;
//     }

//     void printGivenLevel(TreeNode* root, int level, vector<int>& levelVector) {
//         if (!root)
//             return;

//         if (level == 1)
//             levelVector.push_back(root->val);
//         else if (level > 1) {
//             printGivenLevel(root->left, level - 1, levelVector);
//             printGivenLevel(root->right, level - 1, levelVector);
//         }
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.insert(result.begin(), level);  // Insert at the beginning for bottom-up order
        }

        return result;
    }
};
