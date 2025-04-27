class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> transitions = {
        {1, 2, 4}, // 'a' -> 'e', 'i', 'u'
        {0, 2},    // 'e' -> 'a', 'i'
        {1, 3},    // 'i' -> 'e', 'o'
        {2},       // 'o' -> 'i'
        {2, 3}     // 'u' -> 'i', 'o'
    };
    long long solveRE(int n, int vowel) {
        if (n == 1)
            return 1;

        long long count = 0;
        for (int next : transitions[vowel]) {
            count = (count + solveRE(n - 1, next)) % MOD;
        }
        return count;
    }

    int solveME(int n, int vowel, vector<vector<int>>& dp) {
        if (n == 1)
            return 1;
        if (dp[n][vowel] != -1)
            return dp[n][vowel];
        long long count = 0;
        for (int next : transitions[vowel]) {
            count = (count + solveME(n - 1, next, dp)) % MOD;
        }
        return dp[n][vowel] = count;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        long long ans = 0;
        for (int vowel = 0; vowel < 5; ++vowel) {
            ans = (ans + solveME(n, vowel, dp)) % MOD;
        }
        return ans;
    }
};
