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
        vector<vector<long long>> result = matrixExpo(base, n - 1);
        return result[0][0];
    }
};