#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    bool dfs(int node, int destination, vector<list<int>>& adjList, vector<bool>& visited) {
        if (node == destination) {
            return true;
        }
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor] && dfs(neighbor, destination, adjList, visited)) {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> adjList(n);
        vector<bool> visited(n, false);

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return dfs(source, destination, adjList, visited);
    }
};
