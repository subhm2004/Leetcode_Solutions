class Solution {
 public:
  int bfs(vector<vector<int>>& grid, int startRow, int startCol) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;

    // Direction vector for moving up, down, left, right
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int perimeter = 0;

    // Start BFS from the given cell
    q.push({startRow, startCol});
    grid[startRow][startCol] = 2;  // Mark as visited

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (const auto& dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;

        // Check the neighbor
        if (ni < 0 || ni >= rows || nj < 0 || nj >= cols || grid[ni][nj] == 0) {
          // Increment perimeter if out of bounds or water
          ++perimeter;
        } else if (grid[ni][nj] == 1) {
          // Add unvisited land cell to the queue
          q.push({ni, nj});
          grid[ni][nj] = 2;  // Mark as visited
        }
      }
    }

    return perimeter;
  }

  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1) {
          // Start BFS when we find the first land cell
          return bfs(grid, i, j);
        }
      }
    }

    return 0;  // No land found
  }
};
