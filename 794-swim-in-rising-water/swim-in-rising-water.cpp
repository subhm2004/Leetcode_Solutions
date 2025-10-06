class Solution {              // Priority Queue
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    // 4 directions me move karne ke liye vector (right, down, left, up)
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Visited matrix jo track karega ki kaunsa cell visit ho chuka hai
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Min heap (priority queue) jo hamesha minimum time wale cell ko priority dega 
    using T = tuple<int, int, int>;  // (time, i, j)
    priority_queue<T, vector<T>, greater<>> minHeap;

    // Pehle (0,0) ko queue me dalte hain, jo start point hai
    minHeap.emplace(grid[0][0], 0, 0);
    visited[0][0] = true;

    while (!minHeap.empty()) {
      // Sabse kam time wale cell ko nikalte hain
      auto [t, i, j] = minHeap.top();
      minHeap.pop();

      // Agar hum (n-1, n-1) tak pahunch gaye toh return kar do
      if (i == n - 1 && j == n - 1)
        return t; // Destination reached

      // 4 possible directions me move karne ke liye loop
      for (auto [dx, dy] : directions) {
        int x = i + dx, y = j + dy;

        // Agar cell boundary ke andar hai aur pehle visit nahi kiya hai toh process karo
         if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
          visited[x][y] = true;

          // Maximum height wala time update karna hoga kyunki water level  wahi tak jayega 
         int newTime = max(t, grid[x][y]);

          // Naya cell queue me daal do taaki further processing ho sake
          minHeap.emplace(newTime, x, y);
        }
      }
    }

    return -1; // Ye case kabhi execute nahi hoga, bas safety ke liye hai
  }
};

// class Solution {         // Binary Search
// public:
//     // DFS function jo check karega ki (n-1, n-1) tak pahunch sakte hai ya nahi given time `T`
//     bool DFS_can_reach(vector<vector<int>>& grid, int i, int j, int T,
//                        vector<vector<bool>>& visited) {
//         int n = grid.size();

//         // Boundary check, visited check aur height check
//         if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > T)
//             return false;

//         // Agar destination (n-1, n-1) tak pahunch gaye toh return true
//         if (i == n - 1 && j == n - 1)
//             return true;

//         // Current cell ko visited mark kar do
//         visited[i][j] = true;
//         vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//         // Chaaro directions me DFS call karo
//         for (auto [dx, dy] : directions) {
//             if (DFS_can_reach(grid, i + dx, j + dy, T, visited))
//                 return true; // Agar kahin se path mil gaya toh return true
//         }

//         return false; // Agar koi path nahi mila toh return false
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
        
//         // Binary search ka range set karo: Minimum starting point aur max possible height
//         int left = max(grid[0][0], grid[n - 1][n - 1]), right = n * n - 1;

//         while (left < right) {
//             int mid = (left + right) >> 1;
//             vector<vector<bool>> visited(n, vector<bool>(n, false));

//             // Agar DFS ke through (n-1, n-1) tak pahunch sakte hain mid ke saath toh right ko update karo
//             if (DFS_can_reach(grid, 0, 0, mid, visited))
//                 right = mid; // Kam time me pahunchne ki koshish karo
//             else
//                 left = mid + 1; // Time badhane ki zaroorat hai

//         }

//         return left; // Minimum time jo chahiye destination tak pahunchne ke liye
//     }
// };

