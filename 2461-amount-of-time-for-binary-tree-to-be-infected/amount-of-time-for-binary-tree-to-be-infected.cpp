class Solution {
public:
    unordered_map<int, list<int>> adjList;

    // Step 1: Build the graph from tree
    void buildGraph(TreeNode* root, TreeNode* parent) {
        if (!root) return;

        if (parent) {
            int u = root->val;
            int v = parent->val;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }

    // Step 2: BFS function to calculate infection spread time
    int bfs(int start) {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(start);
        visited[start] = true;

        int minutes = -1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                int u = q.front(); q.pop();

                for (int v : adjList[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            minutes++;
        }

        return minutes;
    }

    // Step 3: Main function
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root, nullptr);
        return bfs(start);
    }
};
