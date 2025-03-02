class Solution {
public:
    void buildGraph(unordered_map<int, list<pair<int, int>>>& adjList,
                    vector<vector<int>>& redEdges,
                    vector<vector<int>>& blueEdges) {
        for (auto& edge : redEdges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back({v, 0}); // 0 -> Red
        }

        for (auto& edge : blueEdges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back({v, 1}); // 1 -> Blue
        }
    }

    vector<int> bfs(int n, unordered_map<int, list<pair<int, int>>>& adjList) {
        vector<int> ans(n, -1);
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(
            n, vector<bool>(2, false)); // Track visited states

        q.push({0, 0}); // Start with Red
        q.push({0, 1}); // Start with Blue
        visited[0][0] = visited[0][1] = true;
        ans[0] = 0;

        for (int step = 0; !q.empty(); ++step) {
            int sz = q.size();
            while (sz--) {
                auto [u, prevColor] = q.front();
                q.pop();

                for (auto& [v, edgeColor] : adjList[u]) {
                    if (visited[v][edgeColor] || edgeColor == prevColor)
                        continue;

                    visited[v][edgeColor] = true;
                    q.push({v, edgeColor});
                    if (ans[v] == -1)
                        ans[v] = step + 1;
                }
            }
        }

        return ans;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        unordered_map<int, list<pair<int, int>>> adjList;
        buildGraph(adjList, redEdges, blueEdges);
        return bfs(n, adjList);
    }
};
