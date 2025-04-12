class Solution {
public:
    const int MOD = 1e9 + 7;

    int solveRE(int length, int low, int high, int zero, int one) {
        // Agar current length high se zyada ho gayi, toh yeh valid string nahi hogi
        if (length > high)
            return 0;

        // Agar current length low aur high ke beech hai, toh ek valid string mil gayi
        int count = (length >= low) ? 1 : 0;

        // Recursively zero characters add kar ke naye length ke liye check karo
        count = (count + solveRE(length + zero, low, high, zero, one)) % MOD;

        // Recursively one characters add kar ke naye length ke liye check karo
        count = (count + solveRE(length + one, low, high, zero, one)) % MOD;

        // Total count return karo
        return count;
    }

    int solveME(int length, int low, int high, int zero, int one, vector<int>& dp) {
        if (length > high)
            return 0;

        if (dp[length] != -1)
            return dp[length];

        int count = (length >= low) ? 1 : 0;

        count = (count + solveME(length + zero, low, high, zero, one, dp)) % MOD;
        count = (count + solveME(length + one, low, high, zero, one, dp)) % MOD;

        return dp[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // return solveRE(0, low, high, zero, one);

        vector<int> dp(high + 1, -1);
        return solveME(0, low, high, zero, one, dp);
    }
};
