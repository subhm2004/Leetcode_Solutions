// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     vector<vector<int>> transitions = {
//     {1},        // 0: 'a' → only 'e'
//     {0, 2},     // 1: 'e' → 'a', 'i'
//     {0, 1, 3, 4}, // 2: 'i' → 'a', 'e', 'o', 'u' (no 'i')
//     {2, 4},     // 3: 'o' → 'i', 'u'
//     {0}         // 4: 'u' → only 'a'
// };

//     long long solveRE(int n, int vowel) {
//         if (n == 1)
//             return 1;

//         long long count = 0;
//         for (int next : transitions[vowel]) {
//             count = (count + solveRE(n - 1, next)) % MOD;
//         }
//         return count;
//     }

//     int solveME(int n, int vowel, vector<vector<int>>& dp) {
//         if (n == 1)
//             return 1;
//         if (dp[n][vowel] != -1)
//             return dp[n][vowel];
//         long long count = 0;
//         for (int next : transitions[vowel]) {
//             count = (count + solveME(n - 1, next, dp)) % MOD;
//         }
//         return dp[n][vowel] = count;
//     }

//     int countVowelPermutation(int n) {
//         vector<vector<int>> dp(n + 1, vector<int>(5, -1));
//         long long ans = 0;
//         for (int vowel = 0; vowel < 5; ++vowel) {
//             ans = (ans + solveME(n, vowel, dp)) % MOD;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    using Matrix = vector<vector<ll>>;

    Matrix matrix_multiply(const Matrix &a, const Matrix &b) {
        int n = a.size();
        Matrix ans(n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
        return ans;
    }

    Matrix matrix_exponentiation(Matrix base, int power) {
        int n = base.size();
        Matrix ans(n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i)
            ans[i][i] = 1;

        while (power) {
            if (power % 2)
                ans = matrix_multiply(ans, base);
            base = matrix_multiply(base, base);
            power /= 2;
        }
        return ans;
    }

    int countVowelPermutation(int n) {
        Matrix T = {
            {0, 1, 1, 0, 1}, // a
            {1, 0, 1, 0, 0}, // e
            {0, 1, 0, 1, 0}, // i
            {0, 0, 1, 0, 0}, // o
            {0, 0, 1, 1, 0}  // u
        };

        Matrix power_matrix = matrix_exponentiation(T, n - 1);

        // Initial state: all vowels possible at length 1
        vector<ll> initial = {1, 1, 1, 1, 1};
        vector<ll> ans(5, 0);

        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                ans[i] = (ans[i] + power_matrix[i][j] * initial[j]) % MOD;

        ll total = 0;
        for (int i = 0; i < 5; ++i)
            total = (total + ans[i]) % MOD;

        return total;
    }
};
