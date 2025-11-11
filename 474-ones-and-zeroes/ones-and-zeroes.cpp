
class Solution {
public:
    void convert(vector<string>& strs, vector<pair<int, int>>& nums) {
        for (auto& str : strs) {
            int zero = 0, one = 0;
            for (auto& ch : str) {
                if (ch == '0')
                    zero++;
                else
                    one++;
            }
            nums.push_back({zero, one});
        }
    }

    int solveRE(vector<pair<int, int>>& nums, int i, int m, int n) {
        if (i >= nums.size())
            return 0;

        int zero = nums[i].first;
        int one = nums[i].second;
        int include = 0, exclude = 0;

        if (m - zero >= 0 && n - one >= 0) {
            include = 1 + solveRE(nums, i + 1, m - zero, n - one);
        }

        exclude = solveRE(nums, i + 1, m, n);

        return max(include, exclude);
    }

    int solveME(vector<pair<int, int>>& nums, int i, int m, int n,
                vector<vector<vector<int>>>& dp) {
        if (i >= nums.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int zero = nums[i].first;
        int one = nums[i].second;
        int include = 0, exclude = 0;

        if (m - zero >= 0 && n - one >= 0) {
            include = 1 + solveME(nums, i + 1, m - zero, n - one, dp);
        }

        exclude = solveME(nums, i + 1, m, n, dp);

        return dp[i][m][n] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> nums;
        convert(strs, nums);
        // return solveRE(nums, 0, m, n);
        vector<vector<vector<int>>> dp(
            nums.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solveME(nums, 0, m, n, dp);
    }
};