class Solution {
public:
    bool solveRE(const vector<int>& stones, int index, int lastJump) {
        if (index == stones.size() - 1)
            return true;

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump <= 0)
                continue;

            int nextPos = stones[index] + jump;
            auto it = lower_bound(stones.begin(), stones.end(), nextPos);

            if (it != stones.end() && *it == nextPos) {
                int nextIndex = it - stones.begin();
                if (solveRE(stones, nextIndex, jump))
                    return true;
            }
        }

        return false;
    }

    bool solveME(const vector<int>& stones, int index, int lastJump, vector<vector<int>>& dp) {
        if (index == stones.size() - 1)
            return true;

        if (dp[index][lastJump] != -1)
            return dp[index][lastJump];

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump <= 0) continue;

            int nextPos = stones[index] + jump;
            auto it = lower_bound(stones.begin(), stones.end(), nextPos);

            if (it != stones.end() && *it == nextPos) {
                int nextIndex = it - stones.begin();
                if (solveME(stones, nextIndex, jump, dp))
                    return dp[index][lastJump] = 1;
            }
        }

        return dp[index][lastJump] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // Using 2D DP: dp[index][lastJump]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // lastJump in range [0..n]
        return solveME(stones, 0, 0, dp);
    }
};
