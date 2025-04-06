// class Solution {
//  public:
//   int lengthOfsolveME(vector<int>& nums) {
//     vector<int> tails;

//     for (const int num : nums) {
//       int pos = lowerBound(tails, num);

//       if (pos == tails.size()) {
//         tails.push_back(num);
//       } else {
//         tails[pos] = num;
//       }
//     }

//     return tails.size();
//   }

//  private:
//   int lowerBound(const vector<int>& A, int target) {
//     int left = 0, right = A.size();

//     while (left < right) {
//       int mid = left + (right - left) / 2;
//       if (A[mid] < target)
//         left = mid + 1;
//       else
//         right = mid;
//     }

//     return left;
//   }
// };




// class Solution {
// public:
//     int solveRE(vector<int>& arr, int curr, int prev) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         // include
//         int include = 0;
//         if (prev == -1 || arr[curr] > arr[prev])
//             include = 1 + solveRE(arr, curr + 1, curr);

//         // excude
//         int exclude = 0 + solveRE(arr, curr + 1, prev);

//         int ans = max(include, exclude);
//         return ans;
//     }

//     int solveME(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         if (dp[curr][prev + 1] != -1)
//             return dp[curr][prev + 1];

//         // include
//         int include = 0;
//         if (prev == -1 || arr[curr] > arr[prev])
//             include = 1 + solveME(arr, curr + 1, curr, dp);

//         // excude
//         int exclude = 0 + solveME(arr, curr + 1, prev, dp);

//         dp[curr][prev + 1] = max(include, exclude);
//         return dp[curr][prev + 1];
//     }

//     int lengthOfLIS(vector<int>& nums) {

//         int curr = 0;
//         int prev = -1;
//         // int ans = solveRE(nums, curr, prev );
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solveME(nums, curr, prev, dp);
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};



