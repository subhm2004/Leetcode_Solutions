class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        // Agar heightMap empty hai ya valid nahi hai to return 0 kar do
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int m = heightMap.size(), n = heightMap[0].size();

        // Visited ka ek 2D vector banate hain jo initially false hoga
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Priority queue ka use karte hain jo chhoti height wale cells ko pehle
        // process karega 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Directions ko define karte hain: right, down, left, up (using vector<pair<int, int>>)
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Boundary cells ko priority queue me dalte hain aur visited mark karte
        // hain
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) { // Left aur right boundary
                pq.emplace(heightMap[i][j], i, j);
                visited[i][j] = true; // Is cell ko visited mark kar diya
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) { // Top aur bottom boundary
                if (!visited[i][j]) {
                    pq.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true; // Is cell ko visited mark kar diya
                }
            }
        }

        int waterTrapped = 0; // Total pani jo trap hoga

        // Jab tak priority queue empty na ho, process karte raho
        while (!pq.empty()) {
            auto [height, row, col] = pq.top(); // Current cell nikalte hain
            pq.pop();

            // Har direction me jaane ke liye loop (ab pair ka use karke)
            for (const auto& dir : dirs) {
                int newRow = row + dir.first; // Naya row calculate
                int newCol = col + dir.second; // Naya column calculate

                // Agar cell valid nahi hai ya pehle hi visited hai to continue
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n ||
                    visited[newRow][newCol]) {
                    continue;
                }

                // Trap hone wale pani ka calculation
                waterTrapped += max(0, height - heightMap[newRow][newCol]);

                // Naye height ke saath neighbor cell ko queue me daalo
                pq.emplace(max(height, heightMap[newRow][newCol]), newRow,
                           newCol);
                visited[newRow][newCol] =
                    true; // Is cell ko visited mark kar do
            }
        }

        return waterTrapped; // Total pani jo trap hua return karo
    }
};
