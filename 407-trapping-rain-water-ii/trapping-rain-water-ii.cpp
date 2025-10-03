class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        // Agar array empty hai ya single dimension empty hai to 0 return karo
        if (arr.empty() || arr[0].empty())
            return 0;

        // m = total rows, n = total columns
        int m = arr.size(), n = arr[0].size();
        
        // visited array banao - track karne ke liye ki konsa cell process ho gaya
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Min-heap priority queue banao
        // Tuple me store hoga: (height, row, col)
        // greater<> matlab min-heap - sabse choti height top pe rahegi
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // 4 directions define karo: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // STEP 1: Sabse pehle boundary cells ko queue me push karo
        
        // Left aur right columns process karo (i = 0 to m-1, j = 0 ya n-1)
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {  // j sirf 0 aur n-1 hoga
                pq.emplace(arr[i][j], i, j);  // Queue me daalo
                visited[i][j] = true;          // Mark as visited
            }
        }
        
        // Top aur bottom rows process karo (j = 0 to n-1, i = 0 ya m-1)
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {  // i sirf 0 aur m-1 hoga
                // Agar already visited nahi hai to hi add karo
                // (corners already upar wale loop me add ho gaye honge)
                if (!visited[i][j]) {
                    pq.emplace(arr[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        // Total trapped water ko track karne ke liye variable
        int water_trapped = 0;

        // STEP 2: Queue ko process karo jab tak empty na ho jaye
        while (!pq.empty()) {
            // Min-heap se sabse choti height wala cell nikalo
            // Ye current "water level" ya "barrier height" hai
            auto [height, row, col] = pq.top();  
            pq.pop();

            // STEP 3: Current cell ke 4 neighbors check karo
            for (auto [dr, dc] : directions) {  
                // Neighbor ka row aur column calculate karo
                int new_row = row + dr;
                int new_col = col + dc;

                // Boundary check: agar neighbor matrix ke bahar hai ya already visited hai
                // to skip karo aur next neighbor pe jao
                if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || visited[new_row][new_col])
                    continue;

                // MAIN LOGIC: Pani kitna trap hoga calculate karo
                // Agar current height (barrier) > neighbor ki ground height
                // to difference jitna pani trap hoga
                // Negative case me 0 rahega (max function ki wajah se)
                water_trapped += max(0, height - arr[new_row][new_col]);

                // Neighbor ko queue me daalo with updated height
                // max(height, arr[new_row][new_col]) isliye:
                // - Agar neighbor zyada high hai to wahi naya barrier ban jayega
                // - Agar neighbor low hai to current height barrier rahega
                pq.emplace(max(height, arr[new_row][new_col]), new_row, new_col);
                
                // Neighbor ko visited mark karo taaki dubara process na ho
                visited[new_row][new_col] = true;
            }
        }

        // Total trapped water return karo
        return water_trapped;
    }
};