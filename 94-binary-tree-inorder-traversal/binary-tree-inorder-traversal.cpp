class Solution {
public:
    vector<int> ans;
    
    void inorderTraversalR(TreeNode* root){
        if(!root) return;
        if(root->left){
            inorderTraversal(root->left);
        }
        ans.push_back(root->val);
        if(root->right){
            inorderTraversal(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalR(root);
        return ans;
    }
};

//Mooris traversal
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         TreeNode* curr = root;
//         TreeNode* pre;

//         while (curr != nullptr) {
//             if (curr->left == nullptr) {
//                 result.push_back(curr->val);
//                 curr = curr->right;
//             } else {
//                 pre = curr->left;
                
//                 while (pre->right != nullptr) {
//                     pre = pre->right;
//                 }
                
//                 pre->right = curr;
//                 TreeNode* temp = curr;
//                 curr = curr->left;
//                 temp->left = nullptr;
//             }
//         }

//         return result;
//     }
// };
