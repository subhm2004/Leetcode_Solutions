class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        bool seen_null = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                seen_null = true;
            } else {
                if (seen_null)
                    return false; // If a non-null node appears after a null, it's not complete
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};

// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (!root)
//             return 0;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }

//     bool isValid(TreeNode* root, int index, int totalNodes) {
//         if (!root)
//             return true;
//         if (index > totalNodes)
//             return false;
//         return isValid(root->left, index * 2, totalNodes) &&
//                isValid(root->right, index * 2 + 1, totalNodes);
//     }
//     bool isCompleteTree(TreeNode* root) {
//         int totalNodes = countNodes(root);
//         return isValid(root, 1, totalNodes);
//     }
// };
