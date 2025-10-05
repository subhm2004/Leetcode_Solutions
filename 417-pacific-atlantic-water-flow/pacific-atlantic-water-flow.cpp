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


// class Solution {
// public:
//     // ====================================================================
//     // BFS FUNCTION - Ye function ek ocean se "ulta" flow simulate karta hai
//     // ====================================================================
//     // Parameters:
//     // - heights: Original matrix jisme har cell ki height hai
//     // - q: Queue jisme initially ocean ke border cells hai
//     // - visited: Boolean matrix jo track karta hai ki konse cells is ocean tak pahunch sakte hai
//     // - m, n: Matrix ke dimensions (m = rows, n = columns)
    
//     void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
//              vector<vector<bool>>& visited, int m, int n) {
        
//         // Ye 4 directions hai jisme hum move kar sakte hai
//         // {0,1} = right (same row, column+1)
//         // {1,0} = down (row+1, same column)
//         // {0,-1} = left (same row, column-1)
//         // {-1,0} = up (row-1, same column)
//         vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
//         // BFS ka main loop - jab tak queue me cells hai tab tak chalao
//         while (!q.empty()) {
//             // Queue se front cell nikalo
//             // auto [i, j] matlab automatically i aur j me row aur column assign ho jayega
//             auto [i, j] = q.front();
//             q.pop();  // Is cell ko queue se remove karo
            
//             // Current cell ke sabhi 4 neighbors check karo
//             for (auto [dx, dy] : directions) {
//                 // Naye neighbor cell ka row aur column calculate karo
//                 int x = i + dx;  // New row
//                 int y = j + dy;  // New column
                
//                 // BOUNDARY CHECK: Agar naya cell matrix ke bahar hai to skip karo
//                 // x < 0 matlab row negative hogaya (upar se bahar)
//                 // x >= m matlab row m se bada hogaya (neeche se bahar)
//                 // y < 0 matlab column negative hogaya (left se bahar)
//                 // y >= n matlab column n se bada hogaya (right se bahar)
//                 if (x < 0 || x >= m || y < 0 || y >= n) continue;
                
//                 // AB MAIN LOGIC:
//                 // Condition 1: !visited[x][y] → Ye neighbor cell pehle visit nahi hui
//                 // Condition 2: heights[x][y] >= heights[i][j] → Neighbor ki height current se badi ya equal hai
//                 //
//                 // KYU YE CONDITION?
//                 // Kyunki hum REVERSE flow kar rahe hai!
//                 // Agar neighbor (x,y) ki height >= current cell (i,j) ki height hai,
//                 // to matlab paani neighbor se current cell me FLOW kar sakta hai (neeche ki taraf)
//                 // Aur agar current cell ocean tak reachable hai,
//                 // to neighbor bhi ocean tak reachable hai (kyunki paani waha se bhi neeche flow karega)
//                 if (!visited[x][y] && heights[x][y] >= heights[i][j]) {
//                     // Is neighbor ko mark karo as "reachable to ocean"
//                     visited[x][y] = true;
                    
//                     // Is neighbor ko queue me daalo taaki iske neighbors bhi explore ho sake
//                     q.emplace(x, y);  // emplace push ka optimized version hai
//                 }
//             }
//         }
//     }

//     // ====================================================================
//     // MAIN FUNCTION - Pacific Atlantic Water Flow Problem solve karta hai
//     // ====================================================================
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         // Matrix ki dimensions nikalo
//         int m = heights.size();      // Total rows
//         int n = heights[0].size();   // Total columns
        
//         // Final answer store karne ke liye vector
//         // Har element ek [row, column] pair hoga
//         vector<vector<int>> ans;
        
//         // Pacific ocean tak reachable cells track karne ke liye boolean matrix
//         // Initially sab false hai
//         vector<vector<bool>> pacific(m, vector<bool>(n, false));
        
//         // Atlantic ocean tak reachable cells track karne ke liye boolean matrix
//         // Initially sab false hai
//         vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
//         // Do queues banao - ek Pacific ke liye, ek Atlantic ke liye
//         queue<pair<int, int>> qP, qA;  // qP = Pacific queue, qA = Atlantic queue

//         // ====================================================================
//         // STEP 1: BORDER CELLS KO INITIALIZE KARO
//         // ====================================================================
//         // Yaad rakho:
//         // - Pacific ka border = Top row + Left column
//         // - Atlantic ka border = Bottom row + Right column
        
//         // LEFT COLUMN aur RIGHT COLUMN process karo
//         for (int i = 0; i < m; ++i) {
//             // LEFT COLUMN (column 0) - Ye Pacific se directly connected hai
//             qP.emplace(i, 0);           // Pacific queue me daalo
//             pacific[i][0] = true;       // Mark karo as Pacific-reachable
            
//             // RIGHT COLUMN (column n-1) - Ye Atlantic se directly connected hai
//             qA.emplace(i, n - 1);       // Atlantic queue me daalo
//             atlantic[i][n - 1] = true;  // Mark karo as Atlantic-reachable
//         }
        
//         // TOP ROW aur BOTTOM ROW process karo
//         for (int j = 0; j < n; ++j) {
//             // TOP ROW (row 0) - Ye Pacific se directly connected hai
//             qP.emplace(0, j);           // Pacific queue me daalo
//             pacific[0][j] = true;       // Mark karo as Pacific-reachable
            
//             // BOTTOM ROW (row m-1) - Ye Atlantic se directly connected hai
//             qA.emplace(m - 1, j);       // Atlantic queue me daalo
//             atlantic[m - 1][j] = true;  // Mark karo as Atlantic-reachable
//         }

//         // ====================================================================
//         // STEP 2: BFS CHALAAO DONO OCEANS KE LIYE
//         // ====================================================================
        
//         // PACIFIC BFS: Pacific border se shuru karke andar ki taraf explore karo
//         // Ye sab cells mark karega jo Pacific tak pahunch sakte hai
//         bfs(heights, qP, pacific, m, n);
        
//         // ATLANTIC BFS: Atlantic border se shuru karke andar ki taraf explore karo
//         // Ye sab cells mark karega jo Atlantic tak pahunch sakte hai
//         bfs(heights, qA, atlantic, m, n);

//         // ====================================================================
//         // STEP 3: INTERSECTION NIKALO (DONO ME TRUE WALE CELLS)
//         // ====================================================================
        
//         // Puri matrix traverse karo
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // Agar cell (i,j) DONO oceans tak reachable hai
//                 // matlab pacific[i][j] = true AUR atlantic[i][j] = true
//                 if (pacific[i][j] && atlantic[i][j]) {
//                     // To is cell ko answer me daalo
//                     ans.push_back({i, j});
//                 }
//             }
//         }

//         // Final answer return karo
//         // Ye vector of vectors hai jisme har element [row, col] hai
//         return ans;
//     }
// };

// /*
// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                    TUMHARI SOCH vs SMART APPROACH                          ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ❌ DIRECT WAY (Tumhari Pehli Soch - SLOW)
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// Socho aise: Har cell se shuru karo aur poocho -
// "Kya main Pacific tak pahunch sakta hoon?"
// "Kya main Atlantic tak pahunch sakta hoon?"

// Process:
// ┌─────────────────────────────────────────────────────────────┐
// │ For cell at (i,j):                                          │
// │   → DFS/BFS lagao to check Pacific reachability            │
// │   → Fir se DFS/BFS lagao to check Atlantic reachability    │
// │   → Agar dono reachable hai, to answer me add karo         │
// └─────────────────────────────────────────────────────────────┘

// Problem kya hai?
// └─→ Har cell ke liye COMPLETE traversal karna pad raha hai
// └─→ Total cells = m×n
// └─→ Har cell ke liye traversal = O(m×n)
// └─→ Total Time = O(m×n × m×n) = O(m²n²) \U0001f480 BAHUT SLOW!


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ✅ SMART APPROACH - "ULTA SOCHO" (REVERSE FLOW)
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// Main Idea: Ocean se shuru karo aur ANDAR ki taraf aao! \U0001f30a

// Kyun smart hai?
// └─→ Instead of paani ko island se ocean tak bhejne (forward flow)
// └─→ Hum ocean se island me reverse flow simulate karenge
// └─→ Ek hi baar me sab cells ka answer mil jayega


// ╔════════════════════════════════════════════════════════════════════════════╗
// ║ STEP 1: PACIFIC SE ANDAR AANA                                             ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// Pacific Ocean ka border:
// ┌─────────────────────────────────────┐
// │ • Top row (row 0) - puri row       │
// │ • Left column (column 0) - pura col│
// └─────────────────────────────────────┘

//          Pacific Ocean
//          ↓ ↓ ↓ ↓ ↓
//     ┌───┬───┬───┬───┬───┐
// P → │ ■ │ ■ │ ■ │ ■ │ ■ │
// a   ├───┼───┼───┼───┼───┤
// c → │ ■ │   │   │   │   │
// i   ├───┼───┼───┼───┼───┤
// f → │ ■ │   │   │   │   │
// i   ├───┼───┼───┼───┼───┤
// c → │ ■ │   │   │   │   │
//     └───┴───┴───┴───┴───┘
//     (■ = Pacific border cells)

// Ab in cells se BFS/DFS start karo:

// Rule (CRITICAL): 
// ┌─────────────────────────────────────────────────────────────────┐
// │ Agar neighbor cell ki height >= current cell ki height         │
// │ To wo neighbor bhi Pacific tak pahunch sakta hai!              │
// │                                                                 │
// │ Kyun? Kyunki paani NEECHE ki taraf flow karta hai:            │
// │ Tall neighbor → flow down → current cell → flow → Pacific     │
// └─────────────────────────────────────────────────────────────────┘

// Example:
//     Current cell (height=5) Pacific tak reachable hai
//     Neighbor cell (height=7) check karo
//     → 7 >= 5? Yes!
//     → Matlab paani 7 se 5 me aa sakta hai (downhill)
//     → Aur 5 se Pacific tak ja sakta hai
//     → Therefore, 7 bhi Pacific tak pahunch sakta hai ✓

// Result: pacific[i][j] = true → cell (i,j) Pacific tak pahunch sakta hai


// ╔════════════════════════════════════════════════════════════════════════════╗
// ║ STEP 2: ATLANTIC SE ANDAR AANA                                            ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// Atlantic Ocean ka border:
// ┌─────────────────────────────────────┐
// │ • Bottom row (row m-1) - puri row  │
// │ • Right column (column n-1) - pura │
// └─────────────────────────────────────┘

//     ┌───┬───┬───┬───┬───┐ ← Atlantic
//     │   │   │   │   │ ■ │   Ocean
//     ├───┼───┼───┼───┼───┤ ←
//     │   │   │   │   │ ■ │ 
//     ├───┼───┼───┼───┼───┤ ←
//     │   │   │   │   │ ■ │
//     ├───┼───┼───┼───┼───┤ ←
//     │ ■ │ ■ │ ■ │ ■ │ ■ │
//     └───┴───┴───┴───┴───┘
//      ↑Atlantic Ocean
//     (■ = Atlantic border cells)

// Same process: In border cells se BFS/DFS with same rule
// └─→ heights[neighbor] >= heights[current] → neighbor reachable

// Result: atlantic[i][j] = true → cell (i,j) Atlantic tak pahunch sakta hai


// ╔════════════════════════════════════════════════════════════════════════════╗
// ║ STEP 3: INTERSECTION NIKALO                                               ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// Ab humare paas do boolean matrices hai:
// ┌──────────────────────────────────────────────────────┐
// │ pacific[i][j] = true/false                          │
// │ atlantic[i][j] = true/false                         │
// └──────────────────────────────────────────────────────┘

// Final Answer:
// ┌──────────────────────────────────────────────────────┐
// │ Jo cells dono me TRUE hai → answer me daalo        │
// │                                                     │
// │ if (pacific[i][j] == true && atlantic[i][j] == true) │
// │     ans.push_back({i, j})                          │
// └──────────────────────────────────────────────────────┘


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// \U0001f3af VISUAL EXAMPLE - COMPLETE FLOW
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// Input Matrix (Heights):
//     ┌───┬───┬───┬───┬───┐
//     │ 1 │ 2 │ 2 │ 3 │ 5 │
//     ├───┼───┼───┼───┼───┤
//     │ 3 │ 2 │ 3 │ 4 │ 4 │
//     ├───┼───┼───┼───┼───┤
//     │ 2 │ 4 │ 5 │ 3 │ 1 │
//     ├───┼───┼───┼───┼───┤
//     │ 6 │ 7 │ 1 │ 4 │ 5 │
//     ├───┼───┼───┼───┼───┤
//     │ 5 │ 1 │ 1 │ 2 │ 4 │
//     └───┴───┴───┴───┴───┘

// Pacific BFS ke baad (✓ = reachable to Pacific):
//     ┌───┬───┬───┬───┬───┐
//     │ ✓ │ ✓ │ ✓ │ ✓ │ ✓ │ ← Top row: all reachable
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │   │ ✓ │ ✓ │ ✓ │
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │ ✓ │ ✓ │ ✓ │   │
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │ ✓ │   │ ✓ │ ✓ │
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │   │   │   │ ✓ │
//     └───┴───┴───┴───┴───┘
//     ↑ Left column: all reachable

// Atlantic BFS ke baad (✓ = reachable to Atlantic):
//     ┌───┬───┬───┬───┬───┐
//     │   │   │   │   │ ✓ │ ← Right column: all reachable
//     ├───┼───┼───┼───┼───┤
//     │   │   │ ✓ │ ✓ │ ✓ │
//     ├───┼───┼───┼───┼───┤
//     │   │ ✓ │ ✓ │ ✓ │ ✓ │
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │ ✓ │   │ ✓ │ ✓ │
//     ├───┼───┼───┼───┼───┤
//     │ ✓ │ ✓ │ ✓ │ ✓ │ ✓ │ ← Bottom row: all reachable
//     └───┴───┴───┴───┴───┘

// Final Answer (★ = both Pacific AND Atlantic):
//     ┌───┬───┬───┬───┬───┐
//     │   │   │   │   │ ★ │ (0,4)
//     ├───┼───┼───┼───┼───┤
//     │   │   │ ★ │ ★ │ ★ │ (1,3), (1,4)
//     ├───┼───┼───┼───┼───┤
//     │   │ ★ │ ★ │ ★ │   │ (2,2)
//     ├───┼───┼───┼───┼───┤
//     │ ★ │ ★ │   │ ★ │ ★ │ (3,0), (3,1), (3,4)
//     ├───┼───┼───┼───┼───┤
//     │ ★ │   │   │   │ ★ │ (4,0)
//     └───┴───┴───┴───┴───┘


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ⏱️ TIME & SPACE COMPLEXITY
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// Time Complexity: O(m × n)
// ┌──────────────────────────────────────────────────┐
// │ • Border initialization: O(m + n)               │
// │ • Pacific BFS: O(m × n)                         │
// │   └─→ Har cell maximum ek baar visit hota hai  │
// │ • Atlantic BFS: O(m × n)                        │
// │   └─→ Har cell maximum ek baar visit hota hai  │
// │ • Intersection check: O(m × n)                  │
// │ Total: O(m × n) ✓ LINEAR TIME!                 │
// └──────────────────────────────────────────────────┘

// Space Complexity: O(m × n)
// ┌──────────────────────────────────────────────────┐
// │ • pacific[][] matrix: O(m × n)                  │
// │ • atlantic[][] matrix: O(m × n)                 │
// │ • Queues (worst case): O(m × n)                │
// │ Total: O(m × n)                                 │
// └──────────────────────────────────────────────────┘


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// \U0001f393 KYU YE APPROACH ITNA SMART HAI?
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// Direct Way vs Smart Way:
// ┌─────────────────────────┬──────────────────────────┐
// │ Direct Approach         │ Reverse Flow Approach    │
// ├─────────────────────────┼──────────────────────────┤
// │ Har cell se explore     │ Sirf 2 baar explore      │
// │ m×n cells × O(m×n)      │ O(m×n) + O(m×n)          │
// │ = O(m²n²) \U0001f480            │ = O(m×n) ✅              │
// │                         │                          │
// │ Redundant work          │ Ek hi baar sab solve    │
// │ Same paths baar baar   │ Efficient traversal      │
// └─────────────────────────┴──────────────────────────┘

// Key Insight:
// ┌────────────────────────────────────────────────────────────┐
// │ Paani neeche ki taraf flow karta hai (gravity)           │
// │ Agar cell A se cell B tak paani ja sakta hai:            │
// │   → A ki height >= B ki height                           │
// │                                                           │
// │ Reverse me sochne par:                                   │
// │ Agar B ocean tak reachable hai,                          │
// │ Aur A ki height >= B ki height,                          │
// │   → A bhi ocean tak reachable hai!                       │
// │                                                           │
// │ Is tarik se hum ocean se "climb up" karte hai           │
// │ aur ek hi pass me sab cells discover kar lete hai!      │
// └────────────────────────────────────────────────────────────┘


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// \U0001f4a1 YAAD RAKHNE LAYAK POINTS
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// 1. "Ulta socho" - Problem ko reverse me approach karo
// 2. Ocean se start karo, cells se nahi
// 3. Reverse flow: neighbor_height >= current_height
// 4. Do alag BFS/DFS - ek Pacific, ek Atlantic
// 5. Final answer = intersection of both reachable sets
// 6. Time: O(m×n) - har cell sirf 2 baar visit (optimal!)
// 7. Space: O(m×n) - do boolean matrices aur queues

// */