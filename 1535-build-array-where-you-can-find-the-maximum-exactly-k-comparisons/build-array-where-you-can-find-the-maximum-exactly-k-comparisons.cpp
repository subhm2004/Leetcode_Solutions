class Solution {
public:
    const int MOD = 1e9 + 7;

    int solveRE(int i, int current_maxi, int cost, int n, int m, int k) {
        // agar cost k se zyada ho gayi toh ye path valid nahi hai
        if (cost > k) return 0;

        // agar array ka size n tak pahuch gaya, toh check karo kya cost exactly k hai
        if (i == n) return cost == k ? 1 : 0;

        long count = 0;

        // 1 se leke current_maxi tak ke numbers choose karo
        // inhe choose karne se koi naya maximum nahi milega, isliye cost me koi badlaav nahi hoga
        for (int num = 1; num <= current_maxi; ++num) {
            count = (count + solveRE(i + 1, current_maxi, cost, n, m, k)) % MOD;
        }

        // current_maxi se bade numbers choose karo
        // inhe choose karne se naya maximum milega, isliye cost +1 ho jayega
        for (int num = current_maxi + 1; num <= m; ++num) {
            count = (count + solveRE(i + 1, num, cost + 1, n, m, k)) % MOD;
        }

        return count;
    }

    int solveME(int i, int current_maxi, int cost, int n, int m, int k,
                vector<vector<vector<int>>>& dp) {
        if (cost > k) return 0;
        if (i == n) return cost == k ? 1 : 0;

        if (dp[i][current_maxi][cost] != -1)
            return dp[i][current_maxi][cost];

        long count = 0;

        // 1 se current_maxi tak ke numbers → cost same
        for (int num = 1; num <= current_maxi; ++num) {
            count = (count + solveME(i + 1, current_maxi, cost, n, m, k, dp)) % MOD;
        }

        // current_maxi se bade numbers → naya max, cost +1
        for (int num = current_maxi + 1; num <= m; ++num) {
            count = (count + solveME(i + 1, num, cost + 1, n, m, k, dp)) % MOD;
        }

        return dp[i][current_maxi][cost] = count;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return solveME(0, 0, 0, n, m, k, dp);
    }
};
