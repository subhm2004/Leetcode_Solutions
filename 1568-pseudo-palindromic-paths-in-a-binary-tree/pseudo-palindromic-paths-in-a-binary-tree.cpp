// class Solution {
// public:
//     int ans = 0;

//     void dfs(TreeNode* node, unordered_map<int, int>& freq) {
//         if (!node)
//             return;

//         freq[node->val]++; // include current node

//         // leaf node
//         if (!node->left && !node->right) {
//             int odd_freq_val = 0;
//             for (auto& p : freq) {
//                 if (p.second % 2 == 1)
//                     odd_freq_val++;
//             }
//             if (odd_freq_val <= 1)
//                 ans++;
//         }

//         dfs(node->left, freq);
//         dfs(node->right, freq);

//         freq[node->val]--; // backtrack
//     }

//     int pseudoPalindromicPaths(TreeNode* root) {
//         unordered_map<int, int> freq;
//         dfs(root, freq);
//         return ans;
//     }
// };

// Follow up aayega ki bit manipulation ka use kro mask use hoga
// (can you get rid of passing the map)

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, int mask) {
        if (!node) return;

        // flip bit for node->val
        mask ^= (1 << node->val);

        // leaf node
        if (!node->left && !node->right) {
            // check pseudo-palindromic ya fir seedha power of two check kr lo
            if ((mask & (mask - 1)) == 0)
                ans++;
            // if ((__builtinpopcount(mask) == 1)
            //     ans++;
        }

        dfs(node->left, mask);
        dfs(node->right, mask);
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
