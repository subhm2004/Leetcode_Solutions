class Solution {
public:
    long long dp[10001][10][10][6];
    long long MOD = 1e9+7;

    long long solveME(string &s, int idx, int first, int second, int count) {
        int n = s.size();

        // base case
        if (idx == n) {
            return (count == 5);
        }

        long long &ans = dp[idx][first][second][count];
        if (ans != -1) return ans;

        ans = 0;
        int val = s[idx] - '0';

        // ---------- include ----------
        if (count == 0) {
            ans = (ans + solveME(s, idx + 1, val, second, count + 1)) % MOD;
        }
        else if (count == 1) {
            ans = (ans + solveME(s, idx + 1, first, val, count + 1)) % MOD;
        }
        else if (count == 2) {
            ans = (ans + solveME(s, idx + 1, first, second, count + 1)) % MOD;
        }
        else if (count == 3) {
            if (val == second)
                ans = (ans + solveME(s, idx + 1, first, second, count + 1)) % MOD;
        }
        else if (count == 4) {
            if (val == first)
                ans = (ans + solveME(s, idx + 1, first, second, count + 1)) % MOD;
        }

        // ---------- exclude ----------
        ans = (ans + solveME(s, idx + 1, first, second, count)) % MOD;

        return ans;
    }

    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));
        return solveME(s, 0, 0, 0, 0);
    }
};
