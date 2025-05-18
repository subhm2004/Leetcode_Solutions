class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited, ans);
            }
        }
    }

    void bfs(int start, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int neighbor : adjList[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, list<int>> adjList;
        unordered_map<int, bool> visited;   

        // Build adjacency list
        for (auto& pair : adjacentPairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        // Find the start node (endpoint with only one neighbor)
        int start = 0;
        for (auto& [node, neighbors] : adjList) {
            if (neighbors.size() == 1) {
                start = node;
                break;
            }
        }

        vector<int> ans;
        // dfs(start, adjList, visited, ans);
        bfs(start, adjList, visited, ans);


        return ans;
    }
};
