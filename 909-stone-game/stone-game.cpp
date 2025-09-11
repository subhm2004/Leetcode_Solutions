class Solution {
public:
    int solveME(vector<int>& piles, int left, int right,
                vector<vector<int>>& dp) {
        if (left == right)
            return piles[left];
        if (dp[left][right] != -1)
            return dp[left][right];

        int take_left = piles[left] - solveME(piles, left + 1, right, dp);
        int take_right = piles[right] - solveME(piles, left, right - 1, dp);

        return dp[left][right] = max(take_left, take_right);
    }
    bool stoneGame(vector<int>& piles) {
        // return true;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        return solveME(piles, 0, piles.size() - 1, dp) > 0;
    }
};