class Solution {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    int bfs(int n) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        int min_edge = INT_MAX;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& [v, c] : adjList[u]) {
                min_edge = min(min_edge, c);
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return min_edge;
    }

    int minScore(int n, vector<vector<int>>& roads) {

        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        return bfs(n);
    }
};

// class Solution {
// public:
//     void dfs(int u, unordered_map<int, list<pair<int, int>>>& adjList,
//     vector<bool>& visited, int& min_edge) {
//         visited[u] = true;

//         for (auto& [v, c] : adjList[u]) {
//             min_edge = min(min_edge, c);  // Update the minimum edge weight
//             if (!visited[v]) {
//                 dfs(v, adjList, visited, min_edge);
//             }
//         }
//     }

//     int minScore(int n, vector<vector<int>>& roads) {
//         unordered_map<int, list<pair<int, int>>> adjList;

//         // Construct adjacency list
//         for (auto& road : roads) {
//             int u = road[0], v = road[1], w = road[2];
//             adjList[u].push_back({v, w});
//             adjList[v].push_back({u, w});
//         }

//         vector<bool> visited(n + 1, false);
//         int min_edge = INT_MAX;

//         // Start DFS from node 1
//         dfs(1, adjList, visited, min_edge);

//         return min_edge;
//     }
// };
