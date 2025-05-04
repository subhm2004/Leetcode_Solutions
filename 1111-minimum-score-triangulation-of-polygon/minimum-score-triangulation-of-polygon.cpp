class Solution {      // Partition Dp hai
public:
    int solveRE(vector<int>& values, int i, int j) {
        // Base case: Agar 3 se kam vertices hain, toh triangulation possible nahi hai
        if (i+1 == j) return 0;

        int ans = INT_MAX;

        // Har possible partition ko try karte hain aur cost calculate karte hain
        for (int k = i + 1; k < j; ++k) {
            // Triangle (i, k, j) ka cost calculate karte hain
            int cost = solveRE(values, i, k) + values[i] * values[k] * values[j] + solveRE(values, k, j);
            // Minimum cost ko store karte hain
            ans = min(ans, cost);
        }
        return ans;
    }

    int solveME(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if (i+1 == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for (int k = i + 1; k < j; ++k) {
            int cost = solveME(values, i, k, dp) + values[i] * values[k] * values[j] + solveME(values, k, j, dp);
            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solveME(values, 0, n - 1, dp);
    }
};
