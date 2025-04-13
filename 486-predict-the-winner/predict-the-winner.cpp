class Solution {
public:
    int solveRE(vector<int>& nums, int start, int end) {
        // Agar sirf ek element bacha hai, to wahi return kar do
        if (start == end)
            return nums[start];

        // Start se element lene ka fayda, aur opponent ke response ke baad ka result
        int diffByStart = nums[start] - solveRE(nums, start + 1, end);

        // End se element lene ka fayda, aur opponent ke response ke baad ka result
        int diffByEnd = nums[end] - solveRE(nums, start, end - 1);

        // Dono me se jo maximum fayda de raha ho, usko return karo
        return max(diffByStart, diffByEnd);
    }

    int solveME(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int diffByStart = nums[start] - solveME(nums, start + 1, end, dp);
        int diffByEnd = nums[end] - solveME(nums, start, end - 1, dp);

        return dp[start][end] = max(diffByStart, diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solveME(nums, 0, n - 1, dp) >= 0;
    }
};
