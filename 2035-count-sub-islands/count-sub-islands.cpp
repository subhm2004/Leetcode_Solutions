// class Solution {
// public:
//     vector<pair<int, int>> direction = {
//         {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

//     bool dfs(const vector<vector<int>>& grid1, vector<vector<int>>& grid2,
//              int i, int j) {
//         if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() ||
//             grid2[i][j] == 0)
//             return true;

//         grid2[i][j] = 0; // Mark as visited

//         bool isSubIsland = (grid1[i][j] == 1); // Check if it's land in grid1

//         for (auto [dx, dy] : direction) {
//             isSubIsland &= dfs(grid1, grid2, i + dx, j + dy);
//         }

//         return isSubIsland;
//     }
//     int countSubIslands(vector<vector<int>>& grid1,
//                         vector<vector<int>>& grid2) {
//         int count = 0;

//         for (int i = 0; i < grid2.size(); ++i) {
//             for (int j = 0; j < grid2[0].size(); ++j) {
//                 if (grid2[i][j] == 1) {
//                     count += dfs(grid1, grid2, i, j);
//                 }
//             }
//         }

//         return count;
//     }
// };
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 0; // Mark as visited

        bool isSubIsland = (grid1[i][j] == 1);

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : direction) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < grid2.size() &&
                    newY >= 0 && newY < grid2[0].size() &&
                    grid2[newX][newY] == 1) {
                    
                    if (grid1[newX][newY] == 0)
                        isSubIsland = false; // This part of grid2 is not in grid1

                    grid2[newX][newY] = 0; // Mark visited
                    q.push({newX, newY});
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;

        for (int i = 0; i < grid2.size(); ++i) {
            for (int j = 0; j < grid2[0].size(); ++j) {
                if (grid2[i][j] == 1) {
                    count += bfs(grid1, grid2, i, j);
                }
            }
        }

        return count;
    }
};
