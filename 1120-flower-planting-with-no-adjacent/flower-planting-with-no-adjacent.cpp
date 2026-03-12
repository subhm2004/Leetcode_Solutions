class Solution {
public:
    unordered_map<int, list<int>> adjList;

    // Graph banana - har path ke liye dono directions me edge add kro
    void buildGraph(vector<vector<int>>& paths) {
        for (auto& p : paths) {
            int u = p[0] - 1; // 0-based index
            int v = p[1] - 1; // 0-based index

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void dfs(int node, vector<int>& flower, vector<bool>& visited) {

        // Is node ko visited mark kro
        visited[node] = true;

        // Dekho kaun se flowers already neighbours ne le rakhe hain
        bool used[5] = {false};
        for (auto nbr : adjList[node]) {
            if (flower[nbr] != 0)
                used[flower[nbr]] = true; // Neighbour ka flower mark kro
        }

        // Pehla available flower assign kro jo kisi neighbour ne nahi liya
        for (int f = 1; f <= 4; f++) {
            if (!used[f]) {
                flower[node] = f;
                break;
            }
        }

        // Abhi jo unvisited neighbours hain unpe DFS chalao
        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, flower, visited);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        buildGraph(paths);

        // 0-based: size n, sab 0 se start (matlab koi flower nahi)
        vector<int> flower(n, 0);
        vector<bool> visited(n, false);

        // Har disconnected component ke liye DFS chalao
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, flower, visited);
        }

         return flower;
    }
};