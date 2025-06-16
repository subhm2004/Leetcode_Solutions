/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (root == nullptr)
//             return 0;
//         return max((height(root->left)), (height(root->right))) + 1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {

//         if (root == nullptr)
//             return 0;
//         int opt1 = diameterOfBinaryTree(root->left);
//         int opt2 = diameterOfBinaryTree(root->right);
//         int opt3 = height(root->left) + height(root->right);
//         return max({opt1, opt2, opt3});
//     }
// };

class Solution {
public:
    // Convert Binary Tree to an adjacency List (Graph Representation)
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adjList) {
        if (!root) return;
        if (root->left) {
            adjList[root].push_back(root->left);
            adjList[root->left].push_back(root);
            buildGraph(root->left, adjList);
        }
        if (root->right) {
            adjList[root].push_back(root->right);
            adjList[root->right].push_back(root);
            buildGraph(root->right, adjList);
        }
    }

    // BFS to find the farthest node and its distance
    pair<TreeNode*, int> BFS(unordered_map<TreeNode*, vector<TreeNode*>>& adjList, TreeNode* start) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(start);
        visited[start] = true;

        TreeNode* farthestNode = start;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                farthestNode = curr;

                for (TreeNode* neighbor : adjList[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            if (!q.empty()) distance++;
        }

        return {farthestNode, distance};
    }

    // Find the diameter using BFS
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unordered_map<TreeNode*, vector<TreeNode*>> adjList;
        buildGraph(root, adjList);

        // Step 1: Find the farthest node from an arbitrary node (root)
        TreeNode* firstNode = BFS(adjList, root).first;

        // Step 2: Find the farthest node from `firstNode`, which gives the diameter
        return BFS(adjList, firstNode).second;
    }
};