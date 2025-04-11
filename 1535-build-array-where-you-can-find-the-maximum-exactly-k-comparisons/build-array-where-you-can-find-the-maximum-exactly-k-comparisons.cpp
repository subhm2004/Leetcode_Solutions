class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive solution without memoization (for reference)
    int solveRE(int i, int current_maxi, int cost, int n, int m, int k) {
        if (cost > k) return 0;  // agar cost k se zyada ho gayi toh ye path valid nahi hai
        if (i == n) return cost == k ? 1 : 0;  // agar array complete ban gaya, toh check karo cost sahi hai ya nahi

        long count = 0;

        // woh numbers choose karo jo current_maxi se chhote ya barabar hain → isse cost nahi badhegi
        for (int num = 1; num <= current_maxi; ++num) {
            count = (count + solveRE(i + 1, current_maxi, cost, n, m, k)) % MOD;
        }

        // woh numbers choose karo jo current_maxi se bade hain → naya maximum milega, cost +1 ho jayegi
        for (int num = current_maxi + 1; num <= m; ++num) {
            count = (count + solveRE(i + 1, num, cost + 1, n, m, k)) % MOD;
        }

        return count;
    }

    // Memoized recursive solution
    int solveME(int i, int current_maxi, int cost, int n, int m, int k,
                vector<vector<vector<int>>>& dp) {
        if (cost > k) return 0;
        if (i == n) return cost == k ? 1 : 0;

        if (dp[i][current_maxi][cost] != -1)
            return dp[i][current_maxi][cost];

        long count = 0;

        // numbers ≤ current_maxi → cost same
        count = (count + 1L * current_maxi * solveME(i + 1, current_maxi, cost, n, m, k, dp)) % MOD;

        // numbers > current_maxi → cost +1
        for (int num = current_maxi + 1; num <= m; ++num) {
            count = (count + solveME(i + 1, num, cost + 1, n, m, k, dp)) % MOD;
        }

        return dp[i][current_maxi][cost] = count;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1,
            vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return solveME(0, 0, 0, n, m, k, dp);
    }
};
