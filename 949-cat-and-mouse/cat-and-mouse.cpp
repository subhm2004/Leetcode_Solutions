class Solution {
public:
    int solveME(int chuha, int billi, int move, vector<vector<int>> &graph,
                vector<vector<vector<int>>> &dp,
                map<vector<int>, bool> &visited) {

        if (chuha == 0) return 1;                 // Mouse reached hole
        if (chuha == billi) return 2;             // Cat caught mouse

        if (dp[chuha][billi][move] != -1)         // Already solved
            return dp[chuha][billi][move];

        vector<int> state = {chuha, billi, move};
        if (visited[state]) return 0;             // Cycle detected → Draw
        visited[state] = true;                    // Mark current state visited

        bool draw_mumkin = false;

        if (move == 1) {                           // Mouse turn
            for (int agla_chuha : graph[chuha]) {
                int ans = solveME(agla_chuha, billi, 2, graph, dp, visited);
                if (ans == 1)                   // Mouse can force win
                    return dp[chuha][billi][move] = 1;
                if (ans == 0) draw_mumkin = true;
            }
        } else {                                   // Cat turn
            for (int agli_billi : graph[billi]) {
                if (agli_billi == 0) continue;     // Cat can't enter hole
                int ans = solveME(chuha, agli_billi, 1, graph, dp, visited);
                if (ans == 2)                   // Cat can force win
                    return dp[chuha][billi][move] = 2;
                if (ans == 0) draw_mumkin = true;
            }
        }

        visited[state] = false;                    // Backtrack

        if (draw_mumkin) return dp[chuha][billi][move] = 0;
        return dp[chuha][billi][move] = (move == 1) ? 2 : 1;  // Opponent wins
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, -1)));
        map<vector<int>, bool> visited;
        int ans = 0;

        for (int round = 0; round < n; round++) {
            // Recheck previously drawn states
            for (int chuha = 0; chuha < n; chuha++) {
                for (int billi = 1; billi < n; billi++) {
                    for (int turn = 1; turn <= 2; turn++) {
                        if (dp[chuha][billi][turn] == 0)
                            dp[chuha][billi][turn] = -1;
                    }
                }
            }
            ans = solveME(1, 2, 1, graph, dp, visited);  // Start position
        }

        return ans;
    }
};
