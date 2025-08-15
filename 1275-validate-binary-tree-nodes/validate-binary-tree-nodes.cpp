// class UnionFind {
// public:
//     vector<int> parent;
//     vector<int> rank;

//     // Constructor to initialize parent and rank vectors
//     UnionFind(int n) : parent(n), rank(n, 0) {
//         for (int i = 0; i < n; i++) {
//             parent[i] = i; // Initially, har node apna khud ka parent hai
//         }
//     }

//     // Find function with path compression
//     int find(int i) {
//         if (parent[i] == i)
//             return i;
//         return parent[i] = find(parent[i]); // Path compression se fast banate hain
//     }

//     // Union function by rank
//     bool unionByRank(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);

//         if (x_parent == y_parent)
//             return false; // Cycle detect ho gayi

//         // Union by rank: chhoti tree ko badi tree ke neeche attach karna
//         if (rank[x_parent] < rank[y_parent]) {
//             parent[x_parent] = y_parent;
//         } else if (rank[x_parent] > rank[y_parent]) {
//             parent[y_parent] = x_parent;
//         } else {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++; // Naya root ka rank badha diya
//         }
//         return true;
//     }

//     // Count the number of connected components
//     int countComponents() {
//         int components = 0;
//         for (int i = 0; i < parent.size(); ++i) {
//             if (parent[i] == i) // Agar koi root node hai
//                 components++;
//         }
//         return components;
//     }
// };

// class Solution {
// public:
//     bool validateBinaryTreeNodes(int n, vector<int>& left_child, vector<int>& rught_child) {
//         UnionFind uf(n);
//         vector<int> parent_Count(n, 0); // Parent count track karne ke liye

//         for (int i = 0; i < n; i++) {
//             if (left_child[i] >= 0) {
//                 // Agar ek node ka do se zyada parent ho gaya ya cycle detect ho gayi to galat hai
//                 if (++parent_Count[left_child[i]] > 1 || !uf.unionByRank(i, left_child[i])) {
//                     return false;
//                 }
//             }
//             if (rught_child[i] >= 0) {
//                 if (++parent_Count[rught_child[i]] > 1 || !uf.unionByRank(i, rught_child[i])) {
//                     return false;
//                 }
//             }
//         }

//         return uf.countComponents() == 1; // Ek hi connected component hona chahiye
//     }
// };




class Solution {
public:
    bool bfs(int root, vector<int>& left_child, vector<int>& rught_child, vector<bool>& visited, int& visited_nodes) {
        queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited_nodes++;

            // Left aur Right child check karo
            for (int child : {left_child[node], rught_child[node]}) {
                if (child == -1) continue; // Agar child nahi hai to skip karo
                if (visited[child]) return false; // Cycle detect ho gayi
                visited[child] = true;
                q.push(child);
            }
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& left_child, vector<int>& rught_child) {
        vector<int> parent_Count(n, 0); // Har node ka parent count track karne ke liye
        vector<bool> visited(n, false); // Node visit hui ya nahi track karne ke liye

        // Parent count calculate karo
        for (int i = 0; i < n; i++) {
            if (left_child[i] != -1) parent_Count[left_child[i]]++;
            if (rught_child[i] != -1) parent_Count[rught_child[i]]++;
        }

        // Root find karo (jo kisi ka child nahi hai)
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent_Count[i] == 0) {
                if (root != -1) return false; // Multiple roots mile to invalid tree hai
                root = i;
            }
        }
        
        if (root == -1) return false; // Koi root nahi mila (cycle ya multiple parents ho sakte hain)

        int visited_nodes = 0; // Count of visited nodes
        if (!bfs(root, left_child, rught_child, visited, visited_nodes)) return false;

        // Sabhi nodes visit hone chahiye (Ek hi connected component hona chahiye)
        return visited_nodes == n;
    }
};
