class Solution {
public:
    // Helper function to perform BFS and return the farthest node and its distance
    pair<int, int> BFS(unordered_map<int, list<int>>& adj, int start) {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(start);
        visited[start] = true;

        int farthestNode = start, distance = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                farthestNode = curr;

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            if (!q.empty()) distance++;
        }

        return {farthestNode, distance};
    }

    // Function to find the diameter of a tree using two BFS traversals
     int findDiameter(unordered_map<int, list<int>> adj) {
        //step-1 find the farthest node from a random node - 0
        auto [farthestNode, dist] = BFS(adj, 0);

        //step-2 : the farthestNode we got above is nothing but one end of the diameter of adj

        //step-3 : Find the farthestnode from the node we got above , that will be the other end of diameter - diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }
    // Function to build an adjacency list from edge list using list<int>
    unordered_map<int, list<int>> buildAdj(const vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    // Function to find the minimum possible diameter after merging two trees
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, list<int>> adj1 = buildAdj(edges1);
        unordered_map<int, list<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int mergedDiameter = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, mergedDiameter});
    }
};







// class Solution {
// public:
//     int maxDepth(const vector<vector<int>>& graph, int u, int prev,
//                  int& maxDiameter) {
//         int maxSubDepth1 = 0; // First maximum depth
//         int maxSubDepth2 = 0; // Second maximum depth

//         for (int v : graph[u]) {
//             if (v == prev)
//                 continue;

//             // Recursive call for child node
//             int subDepth = maxDepth(graph, v, u, maxDiameter);

//             // Update the two largest depths
//             if (subDepth > maxSubDepth1) {
//                 maxSubDepth2 = maxSubDepth1;
//                 maxSubDepth1 = subDepth;
//             } else if (subDepth > maxSubDepth2) {
//                 maxSubDepth2 = subDepth;
//             }
//         }

//         // Update the diameter using the two largest depths
//         maxDiameter = max(maxDiameter, maxSubDepth1 + maxSubDepth2);

//         // Return the maximum depth of the current subtree
//         return 1 + maxSubDepth1;
//     }
//     int getDiameter(const vector<vector<int>>& edges) {
//         int n = edges.size() + 1;
//         vector<vector<int>> graph(n);
//         // Build the graph
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//         int maxDiameter = 0;
//         maxDepth(graph, 0, -1, maxDiameter);
//         return maxDiameter;
//     }
//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
//                                   vector<vector<int>>& edges2) {
//         int diameter1 = getDiameter(edges1);
//         int diameter2 = getDiameter(edges2);

//         // Calculate the combined diameter
//         int combinedDiameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;

//         // Return the maximum of the three diameters
//         return max({diameter1, diameter2, combinedDiameter});
//     }
// };




