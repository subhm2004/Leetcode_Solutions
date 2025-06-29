class Solution {
public:
    //  function to calculate XOR of subarray [l..r]
    int calculateXOR(vector<int>& nums, int l, int r) {
        int xorResult = 0;
        for (int i = l; i <= r; i++) {
            xorResult ^= nums[i];
        }
        return xorResult;
    }

     int solveRE(vector<int>& nums, int i, int k) {
        int n = nums.size();

        if (k == 1) {
            return calculateXOR(nums, i, n - 1);
        }

        if (i >= n) return INT_MAX;

        int minMax = INT_MAX;

        for (int j = i; j <= n - k; j++) {
            int leftXOR = calculateXOR(nums, i, j);
            int right = solveRE(nums, j + 1, k - 1);

            if (right != INT_MAX) {
                int maxXOR = max(leftXOR, right);
                minMax = min(minMax, maxXOR);
            }
        }

        return minMax;
    }

     int solveME(vector<int>& nums, int i, int k, vector<vector<int>>& dp) {
        int n = nums.size();

        if (k == 1) {
            return calculateXOR(nums, i, n - 1);
        }

        if (i >= n) return INT_MAX;

        if (dp[i][k] != -1) return dp[i][k];

        int minMax = INT_MAX;

        for (int j = i; j <= n - k; j++) {
            int leftXOR = calculateXOR(nums, i, j);
            int right = solveME(nums, j + 1, k - 1, dp);

            if (right != INT_MAX) {
                int maxXOR = max(leftXOR, right);
                minMax = min(minMax, maxXOR);
            }
        }

        return dp[i][k] = minMax;
    }

     int minXor(vector<int>& nums, int k) {
        int n = nums.size();

         vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

 
        // return solveRE(nums, 0, k);          
        return solveME(nums, 0, k, dp);         
    }
};
