class Solution {
public:
    int solveRE(vector<int>& arr, int curr, int prev) {
        if (curr >= arr.size())
            return 0;

        // include current element if it's increasing
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveRE(arr, curr + 1, curr);

        // exclude current element
        int exclude = solveRE(arr, curr + 1, prev);

        return max(include, exclude);
    }

    int solveME(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= arr.size())
            return 0;

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

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1); // dp[i] = length of ans_LIS ending at i
        vector<int> prev(
            n,
            -1); // prev[i] = index of previous element in ans_LIS ending at i

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the ans_LIS
        vector<int> ans_LIS;
        while (lastIndex != -1) {
            ans_LIS.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(ans_LIS.begin(), ans_LIS.end());

        // Print the ans_LIS
        cout << "Longest Increasing Subsequence: ";
        for (int num : ans_LIS) {
            cout << num << " ";
        }
        cout << endl;

        return maxLength;
    }

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // int lis_length = solveME(nums, 0, -1, dp);
        int lis_length = lengthOfLIS(nums);
        return lis_length >= n - 1;
    }
};
