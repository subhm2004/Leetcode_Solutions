class Solution {
public:
    /*
     * MULTI-SOURCE BFS FUNCTION
     * Kaam: Check karna hai ki kya hum given day pe top row se bottom row tak ja sakte hain
     * 
     * Parameters:
     * - row, col: grid ka size 
     * - cells: har din kon sa cell flood hoga wo array
     * - day: konse din check karna hai (kitne cells flood ho chuke hain)
     * 
     * Returns: agar cross kar sakte hain to true, nahi to false
     */
    bool multi_source_bfs(int row, int col, vector<vector<int>>& cells, int day) {
        // Step 1: Grid banao aur flooded cells ko mark karo
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        // Given day tak ke saare cells ko pani se bhar do (1 = pani)
        // cells[i] mein 1-indexed coordinates hain, isliye 1 minus karo
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;  // 1 matlab pani hai
        }
        
        // Step 2: BFS setup karo
        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // 4 directions
        
        // Step 3: Multi-source BFS - Pehli row ke SAARE land cells se start karo
        // Yahan trick hai: ek ek cell se try karne ke bajaye, saare available 
        // top cells se ek saath BFS start kar dete hain
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {  // 0 matlab zameen hai (pani nahi)
                q.push({0, c});
                visited[0][c] = 1;
            }
        }
        
        // Step 4: BFS chalao
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Check karo ki kya last row pahunch gaye
            if (r == row - 1) return true;  // Bingo! Cross ho gaye
            
            // Char disha mein explore karo
            for (auto &d : direction) {
                int nr = r + d[0];  // naya row
                int nc = c + d[1];  // naya column
                
                // Boundary check, visited nahi hai, aur pani nahi hai
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && 
                    !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return false;  // Bottom row tak nahi pahunch sake
    }
    
    /*
     * BRUTE FORCE APPROACH (COMMENT MEIN HAI)
     * Time Complexity: O(m*n * cells.size()) 
     * 
     * Ye approach har din 1 se cells.size() tak try karti hai aur
     * last wala din dhundhti hai jab crossing possible hai
     * 
     * Logic simple hai: jab tak cross kar sakte ho, karte raho
     * Jaise hi nahi kar sake, wahan ruk jao
     */
    // int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //     int ans = 0;
    //     for (int day = 1; day <= (int)cells.size(); day++) {
    //         if (multi_source_bfs(row, col, cells, day)) {
    //             ans = day; // last possible day update karo
    //         } else {
    //             break; // aage ke din bhi possible nahi honge
    //         }
    //     }
    //     return ans;
    // }
    
    /*
     * OPTIMIZED BINARY SEARCH APPROACH
     * Time Complexity: O(log(cells.size()) * m*n) - Bahut better!
     * 
     * Main Insight: Agar day X pe cross kar sakte hain, to X se pehle ke 
     *               saare din bhi kar sakte hain
     *               Agar day Y pe cross nahi kar sakte, to Y ke baad ke 
     *               saare din bhi nahi kar sakte
     *               
     * Ye monotonic property hai - perfect for binary search!
     */
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Overflow se bachne ke liye
            
            if (multi_source_bfs(row, col, cells, mid)) {
                // Agar day 'mid' pe cross kar sakte hain, to aur late day try karo
                ans = mid;
                left = mid + 1;  // Right half mein search karo
            } else {
                // Agar day 'mid' pe cross nahi kar sakte, to pehle ke din try karo
                right = mid - 1;  // Left half mein search karo
            }
        }
        
        return ans;
    }
};

/*
 * PROBLEM KI DETAILED EXPLANATION:
 * 
 * Scenario: Ek m x n grid hai jo shuru mein saari zameen hai (0).
 * Har din ek cell mein pani aa jata hai (1 ho jata hai).
 * 'cells' array batata hai ki kon sa cell kis din flood hoga.
 * 
 * Goal: Last day dhundhna hai jis din hum abhi bhi top row se bottom row tak ja sakte hain
 * (sirf zameen ke cells pe chalke)
 * 
 * REAL WORLD EXAMPLE:
 * Imagine karo ki tum ek island pe ho, aur har din thoda sa hissa doob raha hai.
 * Tumhe pata karna hai ki last kab tak tum north se south ja sakte ho walking mein.
 * 
 * ALGORITHM KI DETAILED BREAKDOWN:
 * 
 * 1. Multi-source BFS ka concept:
 *    - Normal BFS: Har top cell se alag alag BFS chalana
 *    - Multi-source: Saare available top cells se ek saath start karna
 *    - Ye much faster hai kyunki duplicate work nahi karte
 *    
 *    Example: Agar top row mein 5 cells available hain, to:
 *    - Old way: 5 separate BFS chalana
 *    - New way: Saare 5 ko queue mein daalo aur ek hi BFS chalao
 * 
 * 2. Binary Search ka magic:
 *    - Key insight: Crossing capability monotonic hai
 *    - Matlab: Agar day 10 pe cross kar sakte ho, to day 1-9 pe bhi kar sakte ho
 *    - Agar day 15 pe nahi kar sakte, to day 16+ pe bhi nahi kar sakte
 *    - Isliye binary search perfect hai!
 *    
 *    Example search:
 *    - Days 1-20 available hain
 *    - Mid = 10: Cross kar sakte? Haan -> Right half mein search (11-20)
 *    - Mid = 15: Cross kar sakte? Nahi -> Left half mein search (11-14)
 *    - Aise karte karte exact boundary mil jayegi
 * 
 * 3. Grid construction:
 *    - Har test day ke liye grid ko simulate karna padta hai
 *    - Pehle 'day' number ke cells ko flood kar dete hain
 *    - cells array mein coordinates 1-indexed hain, grid 0-indexed hai
 *    - Isliye cells[i][0]-1 aur cells[i][1]-1 use karte hain
 * 
 * WHY MULTI-SOURCE BFS WORKS BETTER:
 * 
 * Traditional approach:
 * for each cell in top row:
 *     if (BFS from this cell reaches bottom):
 *         return true
 * 
 * Multi-source approach:
 * Put all top row cells in queue
 * Run single BFS
 * If any path reaches bottom, return true
 * 
 * Benefits:
 * - No redundant exploration
 * - Paths can merge and help each other
 * - Single traversal instead of multiple
 * 
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(log(n) * m * n) 
 * - log(n) for binary search iterations
 * - m*n for each BFS traversal
 * - Total cells = cells.size() = worst case m*n
 * 
 * Space Complexity: O(m * n) 
 * - Grid storage: m*n
 * - Visited array: m*n  
 * - BFS queue: worst case m*n
 * 
 * PRACTICAL EXAMPLE:
 * Grid 3x3, cells = [[1,2], [2,1], [3,2], [2,2], [1,1]]
 * 
 * Day 1: (0,1) flooded -> Can cross? YES
 * Day 2: (0,1), (1,0) flooded -> Can cross? YES  
 * Day 3: (0,1), (1,0), (2,1) flooded -> Can cross? YES
 * Day 4: (0,1), (1,0), (2,1), (1,1) flooded -> Can cross? NO
 * 
 * Binary search will find that day 3 is the answer!
 */

/*
Binary search ka rule:

Maximum dhundhna hai: valid answer mile to left = mid + 1 (aur bhi bada search karo)
Minimum dhundhna hai: valid answer mile to right = mid - 1 (aur bhi chota search karo)

Problem name hi hai "Latest Day To Cross" - matlab maximum day chahiye!
Isliye ans = mid; left = mid + 1 sahi hai, ans = mid; right = mid - 1 galat hai.RetryClaude does not have the ability to run the code it generates yet.Claude can make mistakes. Please double-check responses.


 */
