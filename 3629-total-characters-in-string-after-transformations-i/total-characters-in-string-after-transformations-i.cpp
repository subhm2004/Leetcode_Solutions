// class Solution {
// public:
//     static const int MOD = 1e9 + 7;

//     int lengthAfterTransformations(string s, int t) {
//         // Count of each character from 'a' to 'z'
//         vector<long long> count(26, 0);

//         // Count initial characters in the string
//         for (char ch : s) {
//             count[ch - 'a']++;
//         }

//         // Perform transformations for t times
//         for (int step = 0; step < t; ++step) {
//             vector<long long> newCount(26, 0);

//             for (int i = 0; i < 26; ++i) {
//                 if (i == 25) {
//                     // 'z' becomes 'a' and 'b'
//                     newCount[0] = (newCount[0] + count[i]) % MOD;
//                     newCount[1] = (newCount[1] + count[i]) % MOD;
//                 } else {
//                     // 'a' to 'y' becomes next character
//                     newCount[i + 1] = (newCount[i + 1] + count[i]) % MOD;
//                 }
//             }

//             count = newCount; // update for next step
//         }

//         // Calculate final length after all transformations
//         long long total = 0;
//         for (int i = 0; i < 26; ++i) {
//             total = (total + count[i]) % MOD;
//         }

//         return total;
//     }
// };
class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int N = 26;
    using Matrix = vector<vector<long long>>;

    int lengthAfterTransformations(string s, int t) {
        // Step 1: Create the transformation matrix
        Matrix M(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i) {
            if (i == 25) {
                M[i][0] = 1;
                M[i][1] = 1;
            } else {
                M[i][i + 1] = 1;
            }
        }

        // Step 2: Count initial characters in the string
        vector<long long> count(N, 0);
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // Step 3: Raise matrix to the power t
        Matrix Mt = power(M, t);

        // Step 4: Multiply Mt with the count vector
        vector<long long> ansult(N, 0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ansult[i] = (ansult[i] + Mt[j][i] * count[j]) % MOD;

        // Step 5: Compute final total
        long long total = 0;
        for (int i = 0; i < N; ++i)
            total = (total + ansult[i]) % MOD;

        return static_cast<int>(total);
    }

    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix C(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                for (int j = 0; j < N; ++j)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

    Matrix power(Matrix A, int t) {
        Matrix ans(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i) ans[i][i] = 1;
        while (t > 0) {
            if (t & 1) ans = multiply(ans, A);
            A = multiply(A, A);
            t >>= 1;
        }
        return ans;
    }
};
