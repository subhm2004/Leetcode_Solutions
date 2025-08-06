/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sum = 0;  // Global variable to store running sum of greater nodes

    // DFS function to traverse tree in reverse in-order (right -> root -> left)
    void dfs(TreeNode* root) {
        if (!root) return;  // Agar node null ho, toh kuch nahi karna

        dfs(root->right);   // Pehle right subtree visit karo (kyunki yeh BST hai, right wale nodes hamesha bade honge)
        
        sum += root->val;   // Ab tak jitne bhi nodes visit kiye unka sum mein current node ka value add karo
        root->val = sum;    // Current node ka value update kar do with sum
        
        dfs(root->left);    // Ab left subtree visit karo (chhote nodes)
    }

     TreeNode* bstToGst(TreeNode* root) {
        dfs(root);       
        return root;    // Greater Tree ka root return karo
    }
};
