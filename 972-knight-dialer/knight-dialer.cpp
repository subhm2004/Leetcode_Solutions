class Solution {
public:
    const int MOD = 1e9 + 7;

    // Knight ke possible moves
    vector<vector<int>> moves = {
        {4, 6},    // 0
        {6, 8},    // 1
        {7, 9},    // 2
        {4, 8},    // 3
        {0, 3, 9}, // 4
        {},        // 5
        {0, 1, 7}, // 6
        {2, 6},    // 7
        {1, 3},    // 8
        {2, 4}     // 9
    };

    long long count_ways_solveRE(int digit, int len) {
        if (len == 1)
            return 1; // sirf ek digit bacha hai
        long long total = 0;
        for (int next : moves[digit]) {
            total = (total + count_ways_solveRE(next, len - 1)) % MOD;
        }
        return total;
    }

    long long count_ways_solveME(int digit, int len, vector<vector<long long>>& dp) {
        if (len == 1) return 1; 
        
        if (dp[digit][len] != -1) return dp[digit][len]; 
        
        long long total = 0;
        for (int next : moves[digit]) {
            total = (total + count_ways_solveME(next, len - 1, dp)) % MOD;
        }
        
        return dp[digit][len] = total;
    }

    int knightDialer(int n) {
        long long ans = 0;
        vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
        for (int digit = 0; digit <= 9; digit++) {
            // ans = (ans + count_ways_solveME(digit, n)) % MOD;
            ans = (ans + count_ways_solveME(digit, n, dp)) % MOD;
        }
        return ans;
    }
};