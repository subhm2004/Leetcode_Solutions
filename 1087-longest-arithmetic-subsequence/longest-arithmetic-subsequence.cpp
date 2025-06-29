// class Solution {               // LIS based hai 
// public:
//     int solveRE(vector<int>& arr, int curr, int prev, int diff) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         // Include
//         int include = 0;
//         if (prev == -1 || arr[curr] - arr[prev] == diff) {
//             include = 1 + solveRE(arr, curr + 1, curr, diff);
//         }

//         // Exclude
//         int exclude = solveRE(arr, curr + 1, prev, diff);

//         return max(include, exclude);
//     }


//   int solveME(vector<int>& arr, int curr, int prev, int diff, vector<vector<int>>& dp) {
//         if (curr >= arr.size()) {
//             return 0;
//         }
        
//         if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];
        
//         // Include
//         int include = 0;
//         if (prev == -1 || arr[curr] - arr[prev] == diff) {
//             include = 1 + solveME(arr, curr + 1, curr, diff, dp);
//         }

//         // Exclude
//         int exclude = solveME(arr, curr + 1, prev, diff, dp);

//         return dp[curr][prev + 1] = max(include, exclude);
//     }


//   int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 1) return n;
        
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int diff = nums[j] - nums[i]; // Difference calculate karo
//                 vector<vector<int>> dp(n, vector<int>(n + 1, -1)); 
//                 ans = max(ans, 2 + solveME(nums, j + 1, j, diff, dp));
//             }
//         }

//         return ans;
//     }
// };
// https://www.youtube.com/watch?v=S3ocpdBL-7Y&t=1556s
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2) return n; // Any two numbers form an arithmetic sequence

        // DP table where dp[i][diff] stores the longest AP length ending at index i with common difference diff
        vector<vector<int>> dp(n, vector<int>(1001, 0));

        int maxLength = 2; // Minimum AP length is 2 (any two numbers)
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500; // Shift range to avoid negative indices
                
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;

                maxLength = max(maxLength, dp[i][diff]); // Update the global max length
            }
        }

        return maxLength;
    }
};

