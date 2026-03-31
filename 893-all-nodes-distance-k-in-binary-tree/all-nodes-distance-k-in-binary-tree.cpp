class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;

    // Step 1: Mark parents of each node
    void markParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Step 2: DFS to find nodes at distance K
    void findNodes(TreeNode* node, TreeNode* prev, int K) {
        if (!node || K < 0) return;
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        
        if (node->left != prev) findNodes(node->left, node, K - 1);
        if (node->right != prev) findNodes(node->right, node, K - 1);
        if (parent[node] != prev) findNodes(parent[node], node, K - 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        markParents(root);  // Step 1: Find parent nodes
        findNodes(target, nullptr, K);  // Step 2: Find nodes at distance K
        return ans;
    }
};
