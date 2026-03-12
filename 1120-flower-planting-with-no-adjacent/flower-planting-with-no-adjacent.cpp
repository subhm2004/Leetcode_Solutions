class Solution {
public:
    unordered_map<int, list<int>> adjList;

    void buildGraph(vector<vector<int>>& paths) {
        for (auto& p : paths) {
            int u = p[0];
            int v = p[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void dfs(int node, vector<int>& flower, vector<bool>& visited) {

        visited[node] = true;

        bool used[5] = {false};

        // neighbours ke flowers mark kr diye
        for (auto nbr : adjList[node]) {
            if (flower[nbr] != 0)
                used[flower[nbr]] = true;
        }

        // available flower assign kr diye
        for (int f = 1; f <= 4; f++) {
            if (!used[f]) {
                flower[node] = f;
                break;
            }
        }

        // DFS traversal kr diya
        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, flower, visited);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        buildGraph(paths);

        vector<int> flower(n + 1, 0);
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                dfs(i, flower, visited);
        }

        flower.erase(flower.begin());
        return flower;
    }
};
