// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         // Agar tree khali hai toh seedha null return karo
//         if (root == nullptr)
//             return nullptr;

//         // Pehle left aur right subtrees ko store karo
//         TreeNode* const left = root->left;  // Left subtree store karo
//         TreeNode* const right = root->right; // Right subtree store karo

//         // Left me right ka inverted version daal do
//         root->left = invertTree(right);
//         // Right me left ka inverted version daal do
//         root->right = invertTree(left);

//         // Modified tree return karo
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
