class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    
    int solveME(int l, int r, int target) {
        if (r - l < 1) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        if (nums[l] + nums[l + 1] == target) 
            ans = max(ans, 1 + solveME(l + 2, r, target));
        
        if (nums[l] + nums[r] == target) 
            ans = max(ans, 1 + solveME(l + 1, r - 1, target));
        
        if (nums[r - 1] + nums[r] == target) 
            ans = max(ans, 1 + solveME(l, r - 2, target));

        return dp[l][r] = ans;
    }

    int maxOperations(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));

        int a = solveME(2, n - 1, nums[0] + nums[1]);
        int b = solveME(0, n - 3, nums[n - 2] + nums[n - 1]);
        int c = solveME(1, n - 2, nums[0] + nums[n - 1]);

        return 1 + max({a, b, c});
    }
};


// class Solution {
// public:
//     int solveME(const vector<int>& nums, int i, int j, int score, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& dp) {
//         if (i >= j)
//             return 0;

//         if (dp[i][j].count(score))
//             return dp[i][j][score];

//         int deleteFirstTwo = (nums[i] + nums[i + 1] == score)
//                                  ? 1 + solveME(nums, i + 2, j, score, dp)
//                                  : 0;

//         int deleteLastTwo = (nums[j] + nums[j - 1] == score)
//                                 ? 1 + solveME(nums, i, j - 2, score, dp)
//                                 : 0;

//         int deleteFirstAndLast = (nums[i] + nums[j] == score)
//                                      ? 1 + solveME(nums, i + 1, j - 1, score, dp)
//                                      : 0;

//         return dp[i][j][score] = max({deleteFirstTwo, deleteLastTwo, deleteFirstAndLast});
//     }

//     int maxOperations(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
//         return max({
//             solveME(nums, 0, n - 1, nums[0] + nums[1], dp),
//             solveME(nums, 0, n - 1, nums[n - 1] + nums[n - 2], dp),
//             solveME(nums, 0, n - 1, nums[0] + nums[n - 1], dp)
//         });
//     }
// };