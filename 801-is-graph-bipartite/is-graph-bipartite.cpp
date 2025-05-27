// class Solution {
// public:
//     bool isBipartiteBFS(int src, vector<int>& color,
//                         unordered_map<int, list<int>>& adjList) {
//         queue<int> q;
//         q.push(src);
//         color[src] = 0; // Starting node ko color 0 se color karo

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             // Har neighbor ko check karo
//             for (int nbr : adjList[node]) {
//                 if (color[nbr] == -1) { // Agar neighbor ka color -1 hai (yani
//                                         // wo uncolored hai)
//                     color[nbr] = 1 - color[node]; // Opposite color assign karo
//                     q.push(nbr);
//                 } else if (color[nbr] ==
//                            color[node]) { // Agar neighbor ka color same hai
//                                           // parent ke, toh graph bipartite nahi
//                                           // ho sakta
//                     return false;
//                 }
//             }
//         }
//         return true; // Agar saare nodes successfully color ho gaye bina
//                      // contradiction ke, toh bipartite hai
//     }

//     // Main function jo graph ke bipartite hone ko check karta hai
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         unordered_map<int, list<int>> adjList;

//         // Adjacency list banate hain graph ko dekhte hue
//         for (int i = 0; i < n; ++i) {
//             for (int nbr : graph[i]) {
//                 adjList[i].push_back(nbr);
//             }
//         }

//         vector<int> color(n, -1); // Har node ko initially uncolored (-1) rakho

//         // Har component ke liye bipartite check karo
//         for (int i = 0; i < n; ++i) {
//             if (color[i] ==
//                 -1) { // Agar node ka color -1 hai, toh BFS shuru karo
//                 if (!isBipartiteBFS(i, color, adjList)) {
//                     return false; // Agar koi component bipartite nahi hai, toh
//                                   // false return karo
//                 }
//             }
//         }

//         return true; // Agar saare components bipartite hain, toh true return
//                      // karo
//     }
// };
class Solution {
public:
    unordered_map<int, list<int>> adjList; // Adjacency list store karne ke liye

    // Function: Graph ko adjacency list me convert karega
    void buildAdjList(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            for (int nbr : graph[i]) {
                adjList[i].push_back(nbr);
            }
        }
    }

    // DFS function jo bipartite check karega
    bool isBipartiteDFS(int node, vector<int>& color, int currentColor) {
        color[node] = currentColor; // Current node ko color karo

        for (int neighbor : adjList[node]) {
            if (color[neighbor] == -1) { // Agar neighbor uncolored hai
                if (!isBipartiteDFS(neighbor, color, 1 - currentColor)) 
                    return false; // Agar contradiction aayi toh false return karo
            } 
            else if (color[neighbor] == currentColor) { // Agar neighbor ka color same hai
                return false;
            }
        }
        return true;
    }

    // Main function jo bipartite check karega
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Sabhi nodes ko uncolored rakho
        
        buildAdjList(graph); // Adjacency list banao

        // Har component ke liye bipartite check karo
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // Agar node unvisited hai
                if (!isBipartiteDFS(i, color, 0)) 
                    return false;
            }
        }
        return true;
    }
};

