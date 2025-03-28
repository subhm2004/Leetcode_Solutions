using T = tuple<int, int, int>;  // (grid[i][j], i, j)

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {    
    int m = grid.size(), n = grid[0].size();
    vector<int> ans(queries.size(), 0); // Har query ka answer store karne ke liye
    vector<vector<bool>> seen(m, vector<bool>(n, false)); // Cells ko track karne ke liye jo visit ho chuke hain
    priority_queue<T, vector<T>, greater<>> minHeap; // Min-heap jo hamesha sabse chhoti value dega

    // 4 directions mein move karne ke liye {dx, dy}
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Queries ko index ke saath store kar rahe hain taki original order maintain rahe
    vector<pair<int, int>> indexed_Queries;
    for (int i = 0; i < queries.size(); ++i)
      indexed_Queries.emplace_back(queries[i], i);
    sort(indexed_Queries.begin(), indexed_Queries.end()); // Queries ko increasing order mein sort kar diya

    // BFS start karne ke liye (0,0) cell ko heap me daal diya
    minHeap.emplace(grid[0][0], 0, 0);
    seen[0][0] = true;
    int count = 0; // Visit kiye gaye points ka count

    // Har query ke liye process karna hai
    for (auto& [query, index] : indexed_Queries) { 
      // Jab tak heap empty nahi hoti aur top value `query` se chhoti hai, tab tak chalao
      while (!minHeap.empty()) {
        auto [val, x, y] = minHeap.top(); // Heap ke top se (val, x, y) le lo
        if (val >= query)  // Agar current value query ke barabar ya bada hai, toh stop kar do
          break;
        minHeap.pop(); // Process ho gaya, toh hatao
        count++; // Ek aur cell visit kiya, toh count badha do

        // 4 directions mein check karo
        for (auto& [dx, dy] : direction) {
          int nx = x + dx, ny = y + dy;
          // Agar valid index hai aur pehle visit nahi kiya, toh heap mein daal do
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny]) {
            seen[nx][ny] = true; // Mark as visited
            minHeap.emplace(grid[nx][ny], nx, ny); // Heap mein insert karo
          }
        }
      }
      ans[index] = count; // Is query ka answer store kar lo
    }

    return ans; 
  }
};
