class Solution {
 public:
   void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, 
           vector<vector<bool>>& visited, int m, int n) {
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (auto [dx, dy] : directions) {
        int x = i + dx;
        int y = j + dy;
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        if (!visited[x][y] && heights[x][y] >= heights[i][j]) {
          visited[x][y] = true;
          q.emplace(x, y);
        }
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    queue<pair<int, int>> qP, qA;

    for (int i = 0; i < m; ++i) {
      qP.emplace(i, 0);
      qA.emplace(i, n - 1);
      pacific[i][0] = true;
      atlantic[i][n - 1] = true;
    }
    for (int j = 0; j < n; ++j) {
      qP.emplace(0, j);
      qA.emplace(m - 1, j);
      pacific[0][j] = true;
      atlantic[m - 1][j] = true;
    }

    bfs(heights, qP, pacific, m, n);
    bfs(heights, qA, atlantic, m, n);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (pacific[i][j] && atlantic[i][j])
          ans.push_back({i, j});

    return ans;
  }
};
