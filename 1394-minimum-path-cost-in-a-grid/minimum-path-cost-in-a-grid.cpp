using T = tuple<int, int, int>;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();    // total rows
        int n = grid[0].size(); // total columns

        // dist[x][y] = minimum total cost (cell values + move costs)
        // taaki hum row x, column y tak pahunch sakein, starting from kisi bhi
        // cell of row 0 Initially sabko infinity (INT_MAX) set karte hain
        // (matlab abhi tak reachable nahi)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Min-heap priority queue: {cost, row, col}
        priority_queue<T, vector<T>, greater<T>> pq;

        // --- Step 1: Saare possible starting points (row 0 ke har cell) ko
        //     priority queue mein daal do ---
        // Kyunki path kisi bhi cell se row 0 mein start ho sakta hai (question
        // mein clear hai)
        for (int j = 0; j < n; j++) {
            dist[0][j] = grid[0][j]; // shuru mein cost sirf us cell ki value hogi
            pq.push({dist[0][j], 0, j}); // {cost, row=0, col=j} push karo
        }

        // --- Step 2: Dijkstra ka main loop ---
        while (!pq.empty()) {
            // Sabse chhota cost wala state nikal lo (min-heap ki property se)
            auto [cost, x, y] = pq.top();
            pq.pop();


            if (cost > dist[x][y])
                continue;

            // Agar hum already last row mein hain, to yahan se aage move nahi
            // kar sakte (question ke rules ke hisaab se last row se koi move allowed nahi), isliye is state ko process karna band kar do
            if (x == m - 1)
                continue;

            // Current cell ki value nikal lo (moveCost array index karne ke liye zaroori hai, kyunki moveCost[i][j] mein 'i' cell ki VALUE hai, row/col nahi)
            int val = grid[x][y];

            // --- Step 3: Next row ke har possible column 'ny' tak move try kro
            for (int ny = 0; ny < n; ny++) {
                // Naya total cost calculate karo:
                // purana accumulated cost + move karne ka cost (current value se ny column tak) + next row ke us cell ki value
                int newCost = cost + moveCost[val][ny] + grid[x + 1][ny];

                // Agar ye naya cost, (x+1, ny) tak pahunchne ke purane best
                // cost se kam hai, to update karo aur priority queue mein push
                // karo (taaki future mein explore ho)
                if (newCost < dist[x + 1][ny]) {
                    dist[x + 1][ny] = newCost;
                    pq.push({newCost, x + 1, ny});
                }
            }
        }

        // --- Step 4: Answer nikalna ---
        // Last row ke har column mein se jo bhi minimum dist value hai, wahi
        // final answer hai (kyunki path kisi bhi cell pe last row mein end ho
        // sakta hai)
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, dist[m - 1][j]);

        return ans;
    }
};