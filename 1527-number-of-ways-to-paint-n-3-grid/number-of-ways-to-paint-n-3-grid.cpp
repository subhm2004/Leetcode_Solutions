class Solution {
public:
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    vector<vector<int>> states;

    void generate_States(int m, int row, vector<int>& state) {
        if (row == m) {
            states.push_back(state);
            return;
        }
        for (int color = 1; color <= 3; ++color) {
            if (row > 0 && state[row - 1] == color) continue; // no horizontal same colors
            state.push_back(color);
            generate_States(m, row + 1, state);
            state.pop_back();
        }
    }

    bool compatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] == b[i]) return false; // no vertical same colors
        }
        return true;
    }

    Matrix build_Adjacency_Matrix() {
        int size = states.size();
        Matrix adjacency_matrix(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (compatible(states[i], states[j]))
                    adjacency_matrix[i][j] = 1;
        return adjacency_matrix;
    }

    Matrix multiply_Matrices(const Matrix& A, const Matrix& B) {
        int size = A.size();
        Matrix ans(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
        return ans;
    }

    Matrix Matrix_Exponentiation(Matrix A, long long power) {
        int size = A.size();
        Matrix power_Matrix(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i)
            power_Matrix[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1)
                power_Matrix = multiply_Matrices(power_Matrix, A);
            A = multiply_Matrices(A, A);
            power /= 2;
        }
        return power_Matrix;
    }

    int numOfWays(int n) {
        int length = 3; // number of columns fixed = 3
        states.clear();
        vector<int> state;
        generate_States(length, 0, state); // generate all valid rows of length 3

        Matrix adj = build_Adjacency_Matrix();

        // Base cases:
        if (n == 1) return (int)states.size();

        // Calculate adj^(n-1)
        Matrix powerMatrix = Matrix_Exponentiation(adj, n - 1);

        long long total = 0;
        int size = (int)states.size();
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                total = (total + powerMatrix[i][j]) % MOD;

        return (int)total;
    }
};