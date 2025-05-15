class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> transitions = {
    {1},        // 0: 'a' → only 'e'
    {0, 2},     // 1: 'e' → 'a', 'i'
    {0, 1, 3, 4}, // 2: 'i' → 'a', 'e', 'o', 'u' (no 'i')
    {2, 4},     // 3: 'o' → 'i', 'u'
    {0}         // 4: 'u' → only 'a'
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
