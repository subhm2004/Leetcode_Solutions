class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long dp[5001][7][16];
    vector<int> rollMax;

    long long solve(int rollsLeft, int lastFace, int streak) {

        // base case
        if (rollsLeft == 0) return 1;

        // memoization check
        if (dp[rollsLeft][lastFace][streak] != -1)
            return dp[rollsLeft][lastFace][streak];

        long long ways = 0;

        // try every face
        for (int face = 1; face <= 6; face++) {

            if (face == lastFace) {
                // same face → check streak limit
                if (streak < rollMax[face - 1]) {
                    ways = (ways +
                            solve(rollsLeft - 1, face, streak + 1)) % MOD;
                }
            }
            else {
                // new face → streak = 1
                ways = (ways +
                        solve(rollsLeft - 1, face, 1)) % MOD;
            }
        }

        return dp[rollsLeft][lastFace][streak] = ways;
    }

    int dieSimulator(int n, vector<int>& rollMax) {

        this->rollMax = rollMax;
        memset(dp, -1, sizeof(dp));

        return solve(n, 0, 0);
    }
};