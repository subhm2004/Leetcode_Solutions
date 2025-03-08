// class Union_find
// {
//     vector<int> parent; // Parent vector to store the representative of each set
//     vector<int> size;   // Size vector to store the size of each set
//     vector<int> rank;   // Rank vector for optimizing the union operation

// public:
//     // Constructor to initialize the parent, size, and rank arrays
//     Union_find(int n)
//     {
//         parent.resize(n);
//         size.resize(n, 1); // Initial size of each set is 1
//         rank.resize(n, 0); // Initial rank of each set is 0

//         for (int i = 0; i < n; i++)
//         {
//             parent[i] = i; // Har node ka parent apne aap ko banate hain
//         }
//     }

//     // Find function with path compression to find the representative of set containing 'x'
//     int find(int x)
//     {
//         if (x == parent[x])                 // Agar 'x' apne hi parent ko point karta hai
//             return x;                       // Toh x apne set ka representative hai
//         return parent[x] = find(parent[x]); // Path compression: recursively find and update the parent
//     }

//     // UNION_BY_SIZE: Dono sets ko size ke according merge karte hain
//     void UNION_BY_SIZE(int x, int y)
//     {
//         int x_parent = find(x); // x ka representative
//         int y_parent = find(y); // y ka representative

//         if (x_parent == y_parent) // Agar dono already same set mein hain
//             return;

//         // Jo set bada hai, usme chhota set attach karte hain
//         if (size[x_parent] > size[y_parent])
//         {
//             parent[y_parent] = x_parent;
//             size[x_parent] += size[y_parent]; // Size update karte hain
//         }
//         else if (size[x_parent] < size[y_parent])
//         {
//             parent[x_parent] = y_parent;
//             size[y_parent] += size[x_parent]; // Size update karte hain
//         }
//         else
//         {
//             parent[x_parent] = y_parent;
//             size[y_parent] += size[x_parent]; // Size update karte hain
//             rank[y_parent]++;                 // Agar size same hai toh rank ko increase karte hain
//         }
//     }

//     // UNION_BY_RANK: Dono sets ko rank ke according merge karte hain
//     void UNION_BY_RANK(int x, int y)
//     {
//         int x_parent = find(x); // x ka representative
//         int y_parent = find(y); // y ka representative

//         if (x_parent == y_parent) // Agar dono already same set mein hain
//             return;

//         // Rank ke hisaab se merge karte hain
//         if (rank[x_parent] < rank[y_parent])
//         {
//             parent[x_parent] = y_parent; // Chhoti rank wale ko bade rank wale mein merge karte hain
//         }
//         else if (rank[x_parent] > rank[y_parent])
//         {
//             parent[y_parent] = x_parent; // Chhoti rank wale ko bade rank wale mein merge karte hain
//         }
//         else
//         {
//             parent[x_parent] = y_parent; // Agar rank same hai toh ek ko doosre mein merge karte hain
//             rank[y_parent]++;            // Rank ko increase karte hain
//         }
//     }

//     // Count the number of connected components
//     int countComponents()
//     {
//         int components = 0; // Initialize components count
//         for (int i = 0; i < parent.size(); ++i)
//         {
//             if (parent[i] == i) // Agar parent khud apna representative hai, toh wo root node hai
//                 components++;   // Components ka count increase karte hain
//         }
//         return components;
//     }
// };

// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if (connections.size() < n - 1) {
//             // Agar edges ki quantity nodes ko connect karne ke liye enough nahi hai, toh -1 return karte hain
//             return -1;
//         }

//         Union_find uf(n); // Union-Find data structure banate hain

//         // Saare edges ko process karte hain
//         for (const auto& connection : connections) {
//             int u = connection[0];
//             int v = connection[1];
//             uf.UNION_BY_RANK(u, v); // Union karte hain nodes u aur v ko
//         }

//         // Connected components ka count karte hain
//         int components = uf.countComponents();

//         // Minimum number of additional edges ki requirement hamesha (components - 1) hoti hai
//         return components - 1;
//     }

// };

class Solution {
public:
    void bfs(int start, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; // Agar edges kam hain toh connection possible nahi

        unordered_map<int, list<int>> adjList;
        unordered_map<int, bool> visited;

        // Graph adjacency list bana rahe hain
        for (const auto& conn : connections) {
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }

        // Count number of connected components using BFS
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                bfs(i, adjList, visited);
            }
        }

        // Minimum edges required = (components - 1)
        return components - 1;
    }
};


