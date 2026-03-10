class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int last, int limit) {

        // Base: no elements
        if (i == 0 && j == 0)
            return 0;

        // Base: only zeros left
        if (j == 0) {
            if (last == 1) return 0;
            return (i <= limit) ? 1 : 0;
        }

        // Base: only ones left
        if (i == 0) {
            if (last == 0) return 0;
            return (j <= limit) ? 1 : 0;
        }

        if (dp[i][j][last] != -1)
            return dp[i][j][last];

        int result = 0;

        if (last == 0) {
            result = (solve(i-1, j, 0, limit) + solve(i-1, j, 1, limit)) % MOD;

            if (i-1 >= limit)
                result = (result - solve(i-1-limit, j, 1, limit) + MOD) % MOD;
        } 
        else {
            result = (solve(i, j-1, 0, limit) + solve(i, j-1, 1, limit)) % MOD;

            if (j-1 >= limit)
                result = (result - solve(i, j-1-limit, 0, limit) + MOD) % MOD;
        }

        return dp[i][j][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        dp.assign(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % MOD;
    }
};