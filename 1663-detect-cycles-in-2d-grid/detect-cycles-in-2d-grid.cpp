class Solution {
public:
    bool bfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int startX, int startY) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<tuple<int, int, int, int>> q; // (x, y, parentX, parentY)
        q.push({startX, startY, -1, -1});
        visited[startX][startY] = true;
        char targetChar = grid[startX][startY];

        while (!q.empty()) {
            auto [x, y, prevX, prevY] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Agar boundary ke bahar ja rahe ho toh skip karo
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;

                // Agar different character hai toh skip karo
                if (grid[newX][newY] != targetChar)
                    continue;

                // Agar previous node pe wapas ja rahe ho toh skip karo
                if (newX == prevX && newY == prevY)
                    continue;

                // Agar node already visited hai, toh cycle mil gaya
                if (visited[newX][newY])
                    return true;

                // Naya node explore karo
                visited[newX][newY] = true;
                q.push({newX, newY, x, y});
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Har unvisited cell ke liye BFS call karo
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && bfs(grid, visited, i, j))
                    return true;
            }
        }
        return false;
    }
};

// DFS SE KIYA HAI SOLVE

// class Solution {
//  public:
//    bool dfs(const vector<vector<char>>& grid, int x, int y, int prevX, int
//    prevY,
//            char targetChar, vector<vector<bool>>& visited) {
//     visited[x][y] = true;

//     // 4 possible directions: Right, Down, Left, Up
//     vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//     for (auto [dx, dy] : directions) {
//       int newX = x + dx;
//       int newY = y + dy;

//       // Agar boundary ke bahar chale gaye toh skip karo
//       if (newX < 0 || newX >= grid.size() || newY < 0 || newY >=
//       grid[0].size())
//         continue;

//       // Peeche waale cell pe wapas na jayein
//       if (newX == prevX && newY == prevY)
//         continue;

//       // Agar character match nahi karta toh skip karo
//       if (grid[newX][newY] != targetChar)
//         continue;

//       // Agar already visited hai, toh cycle mil gaya
//       if (visited[newX][newY])
//         return true;

//       // DFS se aage check karo
//       if (dfs(grid, newX, newY, x, y, targetChar, visited))
//         return true;
//     }

//     return false;
//   }

//   bool containsCycle(vector<vector<char>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<bool>> visited(m, vector<bool>(n, false));

//     // Har cell check karna hai ki wo kisi cycle ka part hai ya nahi
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         // Agar already visited nahi hai, toh DFS se check karo
//         if (!visited[i][j] && dfs(grid, i, j, -1, -1, grid[i][j], visited)) {
//           return true; // Cycle mil gaya
//         }
//       }
//     }
//     return false; // Koi cycle nahi mili
//   }
// };


// UNION FIND SE KIYA HAI 

// class UnionFind {
// public:
//     vector<int> parent;
//     vector<int> rank;

//     UnionFind(int n) : parent(n), rank(n, 0) {
//         for (int i = 0; i < n; i++) {
//             parent[i] = i; // Har node apni khud ki parent hai initially
//         }
//     }

//     // Path compression wala find function
//     int find(int i) {
//         if (parent[i] == i) 
//             return i;
//         return parent[i] = find(parent[i]); // Path compression
//     }

//     // Union by rank
//     bool unionByRank(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);

//         if (x_parent == y_parent)
//             return true; // Cycle detect ho gaya

//         // Union by rank
//         if (rank[x_parent] < rank[y_parent]) {
//             parent[x_parent] = y_parent;
//         } else if (rank[x_parent] > rank[y_parent]) {
//             parent[y_parent] = x_parent;
//         } else {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++;
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool containsCycle(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         UnionFind uf(m * n);

//         // Directions: Right, Down
//         vector<pair<int, int>> directions = {{0, 1}, {1, 0}};

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (auto [dx, dy] : directions) {
//                     int newX = i + dx;
//                     int newY = j + dy;

//                     if (newX < m && newY < n && grid[i][j] == grid[newX][newY]) {
//                         int node1 = i * n + j;
//                         int node2 = newX * n + newY;

//                         // Agar cycle mil gaya toh return true
//                         if (uf.unionByRank(node1, node2))
//                             return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };
