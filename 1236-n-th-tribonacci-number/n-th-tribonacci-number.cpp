// class Solution {
// public:
//     int solveME(int n, vector<int>& dp) {
//         if (n < 3)
//             return n > 0 ? 1 : 0;
//         if (dp[n] != -1)
//             return dp[n];

//         int ans = solveME(n - 1, dp) + solveME(n - 2, dp) + solveME(n - 3, dp);
//         return dp[n] = ans;
//     }
//     int tribonacci(int n) {

//         vector<int> dp(n + 1, -1);
//         return solveME(n, dp);
//     }
// };

class Solution {
private:
    const long long MOD = 4e9 + 7;

    using Matrix = vector<vector<long long>>;

    // Matrix multiplication for 3x3 matrices
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
        return ans;
    }

    // Matrix exponentiation
    Matrix matrixExpo(Matrix base, int power) {
        int n = base.size();
        Matrix ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            ans[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1)
                ans = multiply(ans, base);
            base = multiply(base, base);
            power /= 2;
        }

        return ans;
    }

public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        Matrix base = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };

        Matrix ans = matrixExpo(base, n - 2);

        // Multiply with base values: T2 = 1, T1 = 1, T0 = 0
        long long Tn = (ans[0][0] * 1 + ans[0][1] * 1 + ans[0][2] * 0) % MOD;
        return static_cast<int>(Tn);
    }
};

