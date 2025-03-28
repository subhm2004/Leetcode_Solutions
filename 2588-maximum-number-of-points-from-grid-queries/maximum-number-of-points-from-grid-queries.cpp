using T = tuple<int, int, int>; // (grid[i][j], i, j)

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        priority_queue<T, vector<T>, greater<>> minHeap;

        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Queries ko index ke saath store kar rahe hain taki original order
        // maintain rahe
        vector<pair<int, int>> indexed_Queries;
        for (int i = 0; i < queries.size(); ++i)
            indexed_Queries.emplace_back(queries[i], i);
        sort(indexed_Queries.begin(), indexed_Queries.end());

        // BFS start karne ke liye (0,0) cell ko heap me daal diya
        minHeap.emplace(grid[0][0], 0, 0);
        seen[0][0] = true;
        int count = 0;

        // Har query ke liye process karna hai
        for (auto& [query, i] : indexed_Queries) {
            while (!minHeap.empty()) {
                auto [val, x, y] = minHeap.top();
                if (val >= query) // Agar current value query ke barabar ya bada
                                  // hai, toh stop kar do
                    break;
                minHeap.pop();
                count++;

                // 4 directions mein check karo
                for (auto& [dx, dy] : direction) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        !seen[nx][ny]) {
                        seen[nx][ny] = true;
                        minHeap.emplace(grid[nx][ny], nx, ny);
                    }
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
