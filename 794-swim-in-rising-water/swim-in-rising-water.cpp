class Solution {
    // Priority Queue (Min Heap) approach - Dijkstra's algorithm jaisa
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Charo directions define kar rahe hain jisme hum move kar sakte hain
        // Right, Down, Left, Up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Visited matrix banate hain jo track karega ki konsa cell already process ho chuka hai
        // Isse hum infinite loop se bachte hain
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Tuple ka type define kar rahe hain: (time, row_index, col_index)
        // Time pe sort hoga kyunki wo pehli value hai
        using T = tuple<int, int, int>;
        
        // Min heap banate hain jo sabse CHHOTE time wale cell ko pehle dega
        // greater<> matlab minimum element top pe rahega
        priority_queue<T, vector<T>, greater<>> minHeap;
        
        // Starting point (0,0) ko heap me daalte hain
        // Initial time = grid[0][0] ki height (kyunki yahi starting time hai)
        minHeap.emplace(grid[0][0], 0, 0);
        
        // Starting cell ko visited mark kar dete hain
        visited[0][0] = true;
        
        // Jab tak heap empty nahi hota, process karte raho
        while (!minHeap.empty()) {
            // Sabse MINIMUM time wala cell nikalte hain heap se
            // t = current time tak ka maximum height jo humne cross kiya
            // i, j = current cell ke coordinates
            auto [t, i, j] = minHeap.top();
            minHeap.pop();
            
            // Agar hum destination (bottom-right corner) tak pahunch gaye
            // toh current time return kar do - yahi answer hai!
            if (i == n - 1 && j == n - 1)
                return t;
            
            // Current cell ke charo neighbors ko explore karte hain
            for (auto [dx, dy] : directions) {
                // Neighbor cell ke coordinates calculate karte hain
                int x = i + dx, y = j + dy;
                
                // Check karte hain:
                // 1. Kya neighbor grid ke andar hai? (boundary check)
                // 2. Kya wo pehle visit nahi hua? (visited check)
                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                    // Neighbor ko visited mark kar dete hain
                    // Taaki dubara process na ho
                    visited[x][y] = true;
                    
                    // Naya time calculate karte hain:
                    // Current time (t) aur neighbor ki height (grid[x][y]) me se MAX lena padega
                    // Kyunki water level ko us height tak wait karna padega
                    int new_time = max(t, grid[x][y]);
                    
                    // Is neighbor ko heap me daal dete hain taaki baad me process ho
                    minHeap.emplace(new_time, x, y);
                }
            }
        }
        
        // Ye line kabhi execute nahi hogi kyunki solution hamesha exist karta hai
        // Bas syntax ke liye aur compiler ko khush karne ke liye rakha hai
        return -1;
    }
};


// ===================================================================================================
// class Solution {  // DFS + Binary Search approach 
// public:
//     // Ye function check karta hai ki kya hum (i,j) se destination tak pohoch sakte hain
//     // jab maximum allowed height T ho
//     bool DFS_can_reach(vector<vector<int>>& grid, int i, int j, int T, vector<vector<bool>>& visited) {
//         int n = grid.size();
        
//         // Boundary check: kya hum grid ke bahar toh nahi ja rahe
//         // Visited check: kya ye cell pehle visit ho chuki hai
//         // Height check: kya current cell ki height T se zyada toh nahi
//         if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > T)
//             return false;
        
//         // Agar hum destination (bottom-right corner) tak pohoch gaye
//         // toh true return karo
//         if (i == n - 1 && j == n - 1)
//             return true;
        
//         // Current cell ko visited mark kar do taaki dobara visit na ho
//         visited[i][j] = true;
        
//         // Charo directions define kar rahe hain: right, down, left, up
//         vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        
//         // Har direction me try karo
//         for (auto [dx,dy] : directions) {
//             // Agar kisi bhi direction se destination tak pohoch gaye
//             // toh true return kar do
//             if (DFS_can_reach(grid, i+dx, j+dy, T, visited))
//                 return true;
//         }
        
//         // Kisi bhi direction se destination nahi mila toh false return karo
//         return false;
//     }
    
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
        
//         // Binary search ki range define kar rahe hain
//         // Left: minimum time jo zaroor chahiye hoga (starting aur ending cell ki max height)
//         // Right: maximum possible time (n*n - 1, kyunki values 0 se n*n-1 tak hain)
//         int left = max(grid[0][0], grid[n-1][n-1]), right = n*n - 1;
        
//         // Answer ko initially maximum value pe set kar rahe hain
//         int ans = right;
        
//         // Binary search start karo time pe
//         while (left <= right) {
//             // Middle time calculate karo
//             int mid = (left + right) >> 1; // >> 1 matlab divide by 2
            
//             // Har binary search iteration ke liye naya visited array banao
//             vector<vector<bool>> visited(n, vector<bool>(n, false));
            
//             // Check karo: kya 'mid' time me hum destination tak pohoch sakte hain?
//             if (DFS_can_reach(grid, 0, 0, mid, visited)) {
//                 // Agar mid time me pohoch sakte hain
//                 ans = mid; // toh mid ko answer me store karo
//                 right = mid - 1; // aur try karo ki kya isse bhi kam time me ja sakte hain
//             } else {
//                 // Agar mid time me nahi pohoch sakte
//                 left = mid + 1; // toh zyada time try karo (left ko aage badhao)
//             }
//         }
        
//         // Minimum time return karo jo humne find kiya
//         return ans;
//     }
// };