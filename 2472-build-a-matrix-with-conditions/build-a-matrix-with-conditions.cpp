class Solution {
public:
    unordered_map<int, list<int>> adjList;

    void topo_Sort_BFS(int k, vector<int>& ans,
                       vector<vector<int>>& conditions) {
        adjList.clear();
        unordered_map<int, int> indegree;

        // Build adjacency list and indegree
        for (auto& cond : conditions) {
            int u = cond[0];
            int v = cond[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        // Queue for nodes with 0 indegree
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // BFS Topological Sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int& nbr : adjList[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> row_Order, col_Order;

        // Get topological sort for rows and columns
        topo_Sort_BFS(k, row_Order, rowConditions);
        topo_Sort_BFS(k, col_Order, colConditions);

        // Check if valid topological sort is possible
        if (row_Order.size() < k || col_Order.size() < k)
            return {};

        // Construct final matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (row_Order[i] == col_Order[j]) {
                    matrix[i][j] = row_Order[i];
                }
            }
        }
        return matrix;
    }
};
