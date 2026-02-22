class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[10001][7][7][7];

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int solveRE(int i, int prev, int prev2, int prev3, int n) {
        // Base case: agar sequence ki length n tak pahuch gayi, toh yeh valid hai
        if (i == n) return 1;

        int total = 0;

        // Har position ke liye 1 se 6 tak ke dice face try karo
        for (int face = 1; face <= 6; face++) {
            // Constraint 1: same number pichle 2 steps mein nahi aana chahiye
            if (face == prev || face == prev2)
                continue;

            // Constraint 2: current face aur previous face ka GCD 1 hona
            // chahiye
            if (prev != 0 && gcd(face, prev) != 1)
                continue;

            // Agar face valid hai, toh next index ke liye recursion call karo
            total = (total + solveRE(i + 1, face, prev, prev2, n)) % MOD;
        }

        return total;
    }

    int solveME(int i, int prev, int prev2, int prev3, int n) {
        if (i == n)
            return 1;

        if (dp[i][prev][prev2][prev3] != -1)
            return dp[i][prev][prev2][prev3];

        int total = 0;

        for (int face = 1; face <= 6; ++face) {
            if (face == prev || face == prev2)
                continue;
            if (prev != 0 && gcd(face, prev) != 1)
                continue;

            total = (total + solveME(i + 1, face, prev, prev2, n)) % MOD;
        }

        return dp[i][prev][prev2][prev3] = total;
    }

    int distinctSequences(int n) {
        // return solveRE(0, 0, 0, 0, n);
        memset(dp, -1, sizeof(dp));
        return solveME(0, 0, 0, 0, n);
    }
};
