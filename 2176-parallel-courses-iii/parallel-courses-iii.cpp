class Solution {
public:
    unordered_map<int, list<int>> adjList;
    vector<int> topoSortBfs(int n) {
        vector<int> result;
        queue<int> q;
        vector<int> indegree(n, 0);

        // Calculate in-degrees
        for (auto& pair : adjList) {
            for (auto& nbr : pair.second) {
                indegree[nbr]++;
            }
        }

        // Push nodes with 0 in-degree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            result.push_back(currentNode);

            for (auto& nbr : adjList[currentNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return result.size() == n ? result : vector<int>{};
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        // Build adjacency list
        for (auto& relation : relations) {
            int u = relation[0] - 1;
            int v = relation[1] - 1;
            adjList[u].push_back(v);
        }

        // Get topological order
        vector<int> order = topoSortBfs(n);
        if (order.empty())
            return -1; // Cycle detected

        vector<int> completion_Time(n, 0);

        // Process nodes in topological order
        for (int node : order) {
            completion_Time[node] += time[node];
            for (int nbr : adjList[node]) {
                completion_Time[nbr] =
                    max(completion_Time[nbr], completion_Time[node]);
            }
        }

        return *max_element(completion_Time.begin(), completion_Time.end());
    }
};
