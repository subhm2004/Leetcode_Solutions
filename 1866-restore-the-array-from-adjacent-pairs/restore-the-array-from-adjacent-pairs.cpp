class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, list<int>> adjList;

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

        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        unordered_set<int> visited;

        result[0] = start;
        visited.insert(start);

        for (int i = 1; i < n; ++i) {
            auto& neighbors = adjList[result[i - 1]];
            // Choose the neighbor not visited yet
            if (!visited.count(neighbors.front())) {
                result[i] = neighbors.front();
            } else {
                result[i] = neighbors.back();
            }
            visited.insert(result[i]);
        }

        return result;
    }
};
