class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // DFS function: Pehle island ko mark karne aur boundary cells ko queue me daalne ke liye
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        
        //Agar boundary ke bahar chale gaye ya cell `1` nahi hai toh return
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;

        grid[i][j] = 2;  //Island ko `2` mark kar diya (visited)
        q.push({i, j});  //Queue me daal diya taaki BFS me use kar sake

        //Har direction me DFS call karna
        for (auto& [dx, dy] : directions) {  
            dfs(grid, i + dx, j + dy, q);
        }
    }

    // \U0001f539 Pehla island dhundh ke usko mark karne ka function
    void markFirstIsland(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        bool found = false;  //Pehla island milne ke baad loop break karne ke liye flag

        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {  //Pehla `1` milte hi DFS chalao
                    dfs(grid, i, j, q);
                    found = true;  //Island mil gaya, loop break kar do
                }
            }
        }
    }

    // \U0001f539 BFS function: Doosre island tak shortest path dhoondhne ke liye
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int steps = 0;
        int m = grid.size(), n = grid[0].size();

        while (!q.empty()) {  //BFS traversal start
            int sz = q.size();  //Current level ke elements count
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                //4 directions me check karo
                for (auto& [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    //Agar valid boundary ke andar hai
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {  
                        if (grid[nx][ny] == 1) return steps;  //Doosra island mil gaya, toh steps return karo
                        if (grid[nx][ny] == 0) {  //Agar water hai toh usko visit karo
                            grid[nx][ny] = 2;  //Water ko mark karo taaki dubara na aaye
                            q.push({nx, ny});  //Queue me daal diya BFS ke liye
                        }
                    }
                }
            }
            ++steps;  //Ek level complete hua toh steps badhao
        }

        return -1;  //Agar kabhi doosra island nahi mila toh -1 return karo (should not happen)
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        markFirstIsland(grid, q);  //  Pehla island mark karo (DFS use karke)
        return bfs(grid, q);  //BFS se doosre island tak shortest distance find karo
    }
};
