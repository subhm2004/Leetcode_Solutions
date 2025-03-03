class Solution {
public:
    int MOD = 1e9 + 7;

    int solveRE(int n, int i, int k, int j) {
        if (i == 0)
            return j == 0 ? 1 : 0; // Agar playlist full ho gayi, toh check
                                   // karein ki sare songs use hue ya nahi
        if (j == 0)
            return 0; // Agar gaane khatam ho gaye toh invalid case

        // Case 1: Last song is new
        long long ans = 1LL * solveRE(n, i - 1, k, j - 1) * (n - (j - 1)) % MOD;

        // Case 2: Last song is old
        if (j > k)
            ans = (ans + 1LL * solveRE(n, i - 1, k, j) * (j - k) % MOD) % MOD;

        return ans;
    }
    
    
    int solveME(int n, int i, int k, int j, vector<vector<int>>& dp) {
        if (i == 0)
            return j == 0 ? 1 : 0; // Agar playlist full ho gayi, toh check karein ki sare songs use hue ya nahi
        if (j == 0)
            return 0; // Agar gaane khatam ho gaye, lekin playlist full nahi hui toh invalid case
        if (dp[i][j] != -1)
            return dp[i][j]; // Agar pehle se computed hai toh return kardo

        // Case 1: Last song naya (new) hai
        long long ans = 1LL * solveME(n, i - 1, k, j - 1, dp) * (n - (j - 1)) % MOD;

        // Case 2: Last song purana (old) hai
        if (j > k)
            ans = (ans + 1LL * solveME(n, i - 1, k, j, dp) * (j - k) % MOD) % MOD;

        return dp[i][j] = ans; 
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal + 1, vector<int>(n + 1, -1)); 
        // return solveRE(n,goal,k,n);
        return solveME(n, goal, k, n, dp);
    }
};
