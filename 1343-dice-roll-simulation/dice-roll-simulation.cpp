class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long dp[5001][7][16]; // dp[rolls_left][last_face][streak]

    // Har step par hume 3 cheezein pata honi chahiye:
    // Kitne rolls abhi baaki hain :- rolls_left
    // Last kaunsa face aaya tha :- last_face
    // Wo face kitni baar continuous chal raha hai :- streak

    vector<int> rollMax;

    long long solve(int rolls_left, int last_face, int streak) {

        // base case
        // Agar rolls khatam ho gaye mtlb ek valid sequence mil gaya.
        if (rolls_left == 0)
            return 1;

        if (dp[rolls_left][last_face][streak] != -1)
            return dp[rolls_left][last_face][streak];

        long long ways = 0;

        // try karte hai sare face ko
        for (int face = 1; face <= 6; face++) {

            if (face == last_face) {
                // same face → check streak limit
                if (streak < rollMax[face - 1]) {
                    ways = (ways + solve(rolls_left - 1, face, streak + 1)) % MOD;
                }
            } else {
                // new face → streak = 1
                ways = (ways + solve(rolls_left - 1, face, 1)) % MOD;
            }
        }

        return dp[rolls_left][last_face][streak] = ways;
    }

    int dieSimulator(int n, vector<int>& rollMax) {

        this->rollMax = rollMax;
        memset(dp, -1, sizeof(dp));

        return solve(n, 0, 0);
    }
};