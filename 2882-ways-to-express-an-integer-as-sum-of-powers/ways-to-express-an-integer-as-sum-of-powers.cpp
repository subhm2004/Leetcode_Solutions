class Solution {
public:
    const int MOD = 1e9 + 7;

    int solveRE(int i, int sum, int target, int x) {
        if (sum == target)
            return 1; // Valid way
        if (i > target || sum > target)
            return 0; // Out of range

        long long power = (long long)pow(i, x);  

        if (power > target) return 0;  

        // Include current number
        int include = solveRE(i + 1, sum + power, target, x) % MOD;
        // Exclude current number
        int exclude = solveRE(i + 1, sum, target, x) % MOD;

        return (include + exclude) % MOD;
    }

    int solveME(int i, int sum, int target, int x, vector<vector<int>>& dp) {
        if (sum == target)
            return 1; 
        if (i > target || sum > target)
            return 0; 

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long power = (long long)pow(i, x);

        if (power > target) return 0;

        int include = solveME(i + 1, sum + power, target, x, dp) % MOD;
        int exclude = solveME(i + 1, sum, target, x, dp) % MOD;

        return dp[i][sum] = (include + exclude) % MOD;
    }

    int numberOfWays(int n, int x) {
        if(!n) return 1;
        // return solveRE(1, 0, n, x);  
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveME(1, 0, n, x, dp);
    }
};
