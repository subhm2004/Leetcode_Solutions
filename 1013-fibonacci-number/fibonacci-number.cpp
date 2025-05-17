// class Solution {
//  public:
//   int fib(int n) {
//     if (n < 2)
//       return n;

//     int a = 0, b = 1;

//     for (int i = 2; i <= n; ++i) {
//       int sum = a + b;
//       a = b;
//       b = sum;
//     }

//     return b;
//   }
// };

// class Solution {
// public:
//     int solveME(int n, vector<int>& dp) {
//         if (n == 1 || n == 0)
//             return n;
//         if (dp[n] != -1)
//             return dp[n];

//         return dp[n] = solveME(n - 1, dp) + solveME(n - 2, dp);
//     }
//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         int ans = solveME(n, dp);
//         return ans;
//     }
// };

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Multiply two n x n matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A,
                                       const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
        return ans;
    }

    // Exponentiate an n x n matrix
    vector<vector<long long>> matrixExpo(vector<vector<long long>> A,
                                         int power) {
        int n = A.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            ans[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1)
                ans = multiply(ans, A);
            A = multiply(A, A);
            power /= 2;
        }
        return ans;
    }

public:
    int fib(int n) {
        if (n == 0)
            return 0;
        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        vector<vector<long long>> ansult = matrixExpo(base, n - 1);
        return ansult[0][0];
    }
};
