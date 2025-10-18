// class Solution {
// public:
//     long helper(int i, int k, const vector<int>& nums,
//                 const vector<long>& prefix, vector<vector<long>>& dp) {
//         if (k == 1) {
//             return prefix[i];
//         }

//         if (dp[i][k] != -1) {
//             return dp[i][k];
//         }

//         long result = LONG_MAX;
//         for (int j = k - 1; j < i; ++j) {
//             result = min(result, max(helper(j, k - 1, nums, prefix, dp),
//                                      prefix[i] - prefix[j]));
//         }

//         return dp[i][k] = result;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         const int n = nums.size();
//         vector<long> prefix(n + 1, 0);

//         partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

//         vector<vector<long>> dp(n + 1, vector<long>(k + 1, -1));

//         return helper(n, k, nums, prefix, dp);
//     }
// };
class Solution {
public:
    bool canSplit(const vector<int>& nums, int k, long maxSum) {
        int splits = 1;
        long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                ++splits;
                currentSum = num;  // Start a new subarray
                if (splits > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0L);
        int ans;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
