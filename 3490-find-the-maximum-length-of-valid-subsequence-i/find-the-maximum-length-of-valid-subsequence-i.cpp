class Solution {
public:
    int solveRE(int i, int prev, int parity, vector<int>& nums) {
        if (i == nums.size())
            return 0;

        // include kr lete hai nums[i] ko
        int include = 0;
        if (prev == -1 || (nums[prev] + nums[i]) % 2 == parity) {
            include = 1 + solveRE(i + 1, i, parity, nums);
        }

        // exclude krte hai  nums[i] ko
        int exclude = solveRE(i + 1, prev, parity, nums);

        return max(include, exclude);
    }

    int solveME_1(int i, int prev, int parity, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1][parity] != -1)
            return dp[i][prev + 1][parity];

        int include = 0;
        if (prev == -1 || (nums[prev] + nums[i]) % 2 == parity) {
            include = 1 + solveME_1(i + 1, i, parity, nums, dp);
        }

        int exclude = solveME_1(i + 1, prev, parity, nums, dp);

        return dp[i][prev + 1][parity] = max(include, exclude);
    }


     int solve(vector<int>& nums) {
        // odd number or even number ka count find krte hai 
        int count_even = 0, count_odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) count_even++;
            else count_odd++;
        }

        // alternating parity subsequence banate hai 
        int alternating_length = 1; // At ek number to hoga hi starting me
        int prev_parity = nums[0] % 2;

        for (int i = 1; i < nums.size(); ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prev_parity) {
                alternating_length++;
                prev_parity = currParity;
            }
        }

        return max({count_even, count_odd, alternating_length});
    }

    int maximumLength(vector<int>& nums) {
        // mod 2 krne se do values (parity) aa skti hai 0 and 1
        // int n = nums.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        // int even = solveME_1(0, -1, 0, nums, dp);
        // int odd = solveME_1(0, -1, 1, nums, dp);
        // return max(even, odd);

        return solve(nums);
    
    }
};
