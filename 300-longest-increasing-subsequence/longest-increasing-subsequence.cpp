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

//     int lengthOfans_LIS(vector<int>& nums) {

//         int curr = 0;
//         int prev = -1;
//         // int ans = solveRE(nums, curr, prev );
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solveME(nums, curr, prev, dp);
//     }
// };

// class Solution {
// public:
//     int lengthOfans_LIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int maxLength = 1;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             maxLength = max(maxLength, dp[i]);
//         }

//         return maxLength;
//     }
// };


// class Solution {
// public:
//     int lengthOfans_LIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {          // Bottom up easy hi hai 
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);          // dp[i] = length of ans_LIS ending at i
        vector<int> prev(n, -1);       // prev[i] = index of previous element in ans_LIS ending at i

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1 ) {
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
};


