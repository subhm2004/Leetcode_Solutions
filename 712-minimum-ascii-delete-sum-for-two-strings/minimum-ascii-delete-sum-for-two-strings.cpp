class Solution { // Edit Distance varient hai
public:
    int solveRE(string& a, string& b, int i, int j) {
        // Base case: agar s1 khatam ho gaya
        if (i == a.length()) {
            int sum = 0;
            while (j < b.length()) {
                sum += b[j++];
            }
            return sum;
        }

        // Base case: agar s2 khatam ho gaya
        if (j == b.length()) {
            int sum = 0;
            while (i < a.length()) {
                sum += a[i++];
            }
            return sum;
        }

         if (a[i] == b[j]) {
            return solveRE(a, b, i + 1, j + 1);
        } else {
            int delete_From_A = int(a[i]) + solveRE(a, b, i + 1, j);
            int delete_From_B = int(b[j]) + solveRE(a, b, i, j + 1);
            return min(delete_From_A, delete_From_B);
        }
    }

    int solveME(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    if (i == a.length()) {
        int sum = 0;
        while (j < b.length()) {
            sum += b[j++];
        }
        return sum;
    }

    if (j == b.length()) {
        int sum = 0;
        while (i < a.length()) {
            sum += a[i++];
        }
        return sum;
    }

     if (dp[i][j] != -1)
        return dp[i][j];

     if (a[i] == b[j]) {
        return dp[i][j] = solveME(a, b, i + 1, j + 1, dp);
    } else {
        int delete_From_A = int(a[i]) + solveME(a, b, i + 1, j, dp);
        int delete_From_B = int(b[j]) + solveME(a, b, i, j + 1, dp);
        return dp[i][j] = min(delete_From_A, delete_From_B);
    }
}

int minimumDeleteSum(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveME(s1, s2, 0, 0, dp);
}

};