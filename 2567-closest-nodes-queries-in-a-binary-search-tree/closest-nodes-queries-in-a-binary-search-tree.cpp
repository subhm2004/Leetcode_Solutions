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


// class Solution {
// public:
//     void find_min_max(TreeNode* root, int querie_value, int& mini, int& maxi) {
//         TreeNode* node = root;
//         while (node) {
//             if (node->val == querie_value) {
//                 mini = maxi = node->val;
//                 return;
//             } else if (node->val < querie_value) {// agar value choti hai to badi side me search kro 
//                 mini = node->val;   
//                 node = node->right;
//             } else { // agar value badi hai to choti side me search kro
//                 maxi = node->val;   
//                 node = node->left;
//             }
//         }
//     }

//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         vector<vector<int>> ans;

//         for (int q : queries) {
//             int mini = -1, maxi = -1;
//             find_min_max(root, q, mini, maxi);
//             ans.push_back({mini, maxi});
//         }

//         return ans;
//     }
// };

class Solution {
public:
     void inorder(TreeNode* root, vector<int>& sorted) {
        if (!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }

     pair<int,int> solve_optimized(const vector<int>& sorted, int target) {
        int n = sorted.size();
        int low = 0, high = n - 1;
        int mini = -1, maxi = -1;

        // find mini 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sorted[mid] <= target) {
                mini = sorted[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // find maxi 
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sorted[mid] >= target) {
                maxi = sorted[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {mini, maxi};
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sorted;
        inorder(root, sorted);   

        vector<vector<int>> ans;
        for (int q : queries) {
            auto [mini, maxi] = solve_optimized(sorted, q);   
            ans.push_back({mini, maxi});
         }

        return ans;
    }
};


