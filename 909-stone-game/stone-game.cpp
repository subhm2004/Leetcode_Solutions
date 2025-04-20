// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         return true;
//     }
// };
class Solution {
public:
    int solveRE(const vector<int>& piles, int left, int right) {
        if (left == right) {
            return piles[left];
        }

        int takeLeft = piles[left] - solveRE(piles, left + 1, right);
        int takeRight = piles[right] - solveRE(piles, left, right - 1);

        return max(takeLeft, takeRight);
    }

    int solveME(const vector<int>& piles, int left, int right,
                vector<vector<int>>& dp) {
        if (left == right) {
            return piles[left];
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int takeLeft = piles[left] - solveME(piles, left + 1, right, dp);
        int takeRight = piles[right] - solveME(piles, left, right - 1, dp);

        return dp[left][right] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveME(piles, 0, n - 1,dp) > 0;
    }
};
