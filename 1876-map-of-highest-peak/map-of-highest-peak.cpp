class Solution {
public:
 // BFS function jo multi-source BFS lagata hai
  void bfs(const vector<vector<int>>& isWater, vector<vector<int>>& ans, int m, int n) {
    queue<pair<int, int>> q;

    // Sabhi water cells ko queue me daal do aur unki height ko 0 set karo
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j] == 1) {       // Agar cell water hai
          q.push({i, j});               // BFS ke liye queue me daalo
          ans[i][j] = 0;                // Water cells ki height 0 hoti hai
        }
      }
    }

    // 4 directions me move karne ke liye vector: right, down, left, up
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // BFS loop — jab tak queue khali na ho
    while (!q.empty()) {
      auto [i, j] = q.front(); // Current cell le lo
      q.pop();

      // Har 4 directions me check karo
      for (auto& [dx, dy] : dirs) {
        int x = i + dx, y = j + dy;  // Neighbor cell ka coordinate

        // Agar neighbor valid hai aur abhi tak visit nahi hua (ans[x][y] == -1)
        if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
          ans[x][y] = ans[i][j] + 1; // Uski height = current height + 1
          q.push({x, y});            // BFS ke liye queue me daal do
        }
      }
    }
  }

  // Main function jo highest peak grid return karta hai
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();       // Row count
    int n = isWater[0].size();    // Column count

    // Answer grid initialize karo -1 se (matlab unvisited)
    vector<vector<int>> ans(m, vector<int>(n, -1));

    // BFS call karo jo sabhi water cells se start hoga
    bfs(isWater, ans, m, n);

    return ans; // Final height grid return karo
  }
};
