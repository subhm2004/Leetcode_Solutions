class Solution {
public:
    int solveRE(vector<int>& arr, int curr, int prev) {
        if (curr >= arr.size()) return 0;

        // include current element if it's increasing
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveRE(arr, curr + 1, curr);

        // exclude current element
        int exclude = solveRE(arr, curr + 1, prev);

        return max(include, exclude);
    }

    int solveME(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= arr.size()) return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // include current element if it's increasing
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveME(arr, curr + 1, curr, dp);

        // exclude current element
        int exclude = solveME(arr, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int lis_length = solveME(nums, 0, -1, dp);
        return lis_length >= n - 1;
    }
};
