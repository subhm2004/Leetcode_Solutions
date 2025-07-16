class Solution {
public:
    int solveRE(int i, int prev, int parity, vector<int>& nums) { // ye solution ache hai lekin efficient hai honge 
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

    // ISME HUMNE PREVIOUS ELEMENT KO NA LEKE SEEDHA PREVIOUS PARITY KA CONCEPT LE LIYA
    int solveRE_2(int i, int prev_parity, int target_parity, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int include = 0;
        int currParity = nums[i] % 2;

        if (prev_parity == -1 || (prev_parity + currParity) % 2 == target_parity) {
            include = 1 + solveRE_2(i + 1, currParity, target_parity, nums);
        }

        int exclude = solveRE_2(i + 1, prev_parity, target_parity, nums);

        return max(include, exclude);
    }

    int solveME_2(int i, int prev_parity, int target_parity, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;

        if (dp[i][prev_parity + 1] != -1) return dp[i][prev_parity + 1];

        int include = 0;
        int currParity = nums[i] % 2;

        if (prev_parity == -1 || (prev_parity + currParity) % 2 == target_parity) {
            include = 1 + solveME_2(i + 1, currParity, target_parity, nums, dp);
        }

        int exclude = solveME_2(i + 1, prev_parity, target_parity, nums, dp);

        return dp[i][prev_parity + 1] = max(include, exclude);
    }

    int maximumLength(vector<int>& nums) {
        // mod 2 krne se do values (parity) aa skti hai 0 and 1
        int n = nums.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        // int even = solveME_1(0, -1, 0, nums, dp);
        // int odd = solveME_1(0, -1, 1, nums, dp);
        // return max(even, odd);

        // return solve(nums);

        // int even = solveRE_2(0, -1, 0, nums); // target: even pair sums
        // int odd = solveRE_2(0, -1, 1, nums);  // target: odd pair sums
        // return max(even, odd);

        vector<vector<int>> dp_even(n, vector<int>(3, -1));
        vector<vector<int>> dp_odd(n, vector<int>(3, -1));

        int even_ans = solveME_2(0, -1, 0, nums, dp_even);  
        int odd_ans = solveME_2(0, -1, 1, nums, dp_odd);   

        return max(even_ans, odd_ans);
    
    }
};
