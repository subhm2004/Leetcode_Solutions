class Solution {
public:
    unordered_map<int, list<int>> adjList; // Graph ko adjacency list ke form me store kar rahe hain

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Dono nodes ko ek dusre se connect kar rahe hain
        adjList[v].push_back(u); // Kyunki graph undirected hai, isliye dono taraf edge add karni hogi
    }

    pair<int, int> bfs(int src, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(src);         // BFS queue me start node daal rahe hain
        visited[src] = true; // Is node ko visited mark kar rahe hain

        int nodes = 0, edges = 0; // Yeh variables component ke nodes aur edges count karne ke liye hain

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            nodes++; // Ek aur node visit kar li

            edges += adjList[frontNode].size(); // Us node ke jitne edges hain, unko count kar rahe hain

            for (auto nbr : adjList[frontNode]) { // Saare neighbours ko traverse karenge
                if (!visited[nbr]) { // Agar neighbour pehle visit nahi hua hai toh queue me daalenge
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return {nodes, edges}; // Component ka total node count aur edge count return karenge
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, bool> visited; // Har node ka visited status track karne ke liye

        // Graph banane ke liye adjacency list prepare kar rahe hain
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            addEdge(u, v);
        }

        int count = 0; // Complete components ka count store karne ke liye
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Agar node abhi tak visit nahi hui hai toh naya component start hoga
                auto [nodes, edges] = bfs(i, visited); // BFS run karke component ka size aur edges nikal rahe hain
                if (nodes * (nodes - 1) == edges) { // Agar component ek complete graph hai toh count badhayenge
                    count++;
                }
            }
        }
        return count; // Final count return karenge
    }
};


// class Solution {
// public:
//     unordered_map<int, list<int>> adjList; // Graph ko adjacency list ke form
//     me store kar rahe hain

//     void addEdge(int u, int v) {
//         adjList[u].push_back(v); // Dono nodes ko ek dusre se connect kar
//         rahe hain adjList[v].push_back(u); // Kyunki graph undirected hai,
//         isliye dono taraf edge add karni hogi
//     }

//     void dfs(int node, unordered_map<int, bool>& visited, int& nodes, int&
//     edges) {
//         visited[node] = true; // Is node ko visited mark kar rahe hain
//         nodes++; // Component me ek aur node add ho gayi
//         edges += adjList[node].size(); // Current node ke saare edges count
//         kar rahe hain

//         for (auto nbr : adjList[node]) { // Saare neighbours ko traverse
//         karenge
//             if (!visited[nbr]) { // Agar neighbour pehle visit nahi hua hai
//             toh DFS call karenge
//                 dfs(nbr, visited, nodes, edges);
//             }
//         }
//     }

//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         unordered_map<int, bool> visited; // Har node ka visited status track
//         karne ke liye

//         // Graph banane ke liye adjacency list prepare kar rahe hain
//         for (auto& edge : edges) {
//             addEdge(edge[0], edge[1]);
//         }

//         int count = 0; // Complete components ka count store karne ke liye
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) { // Agar node abhi tak visit nahi hui hai toh
//             naya component start hoga
//                 int nodes = 0, edges = 0;
//                 dfs(i, visited, nodes, edges); // DFS run karke component ka
//                 size aur edges nikal rahe hain

//                 // Ek complete graph ke liye, edges ki sankhya nodes * (nodes
//                 - 1) honi chahiye if (nodes * (nodes - 1) == edges) {
//                     count++; // Agar condition match hoti hai toh count
//                     badhayenge
//                 }
//             }
//         }
//         return count; // Final count return karenge
//     }
// };
