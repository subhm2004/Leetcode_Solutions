// class Solution {
// public:
//     int minimumSum(vector<int>& nums) {
//         int minSum = INT_MAX;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] < nums[j] && nums[k] < nums[j]) {
//                         int sum = nums[i] + nums[j] + nums[k];
//                         minSum = min(minSum, sum);
//                     }
//                 }
//             }
//         }
//         return (minSum == INT_MAX) ? -1 : minSum;
//     }
// };
class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    vector<int> minLeft(n), minRight(n);

    // Compute the minimum prefix values
    minLeft[0] = nums[0];
    for (int i = 1; i < n; ++i)
      minLeft[i] = min(minLeft[i - 1], nums[i]);

    // Compute the minimum suffix values
    minRight[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
      minRight[i] = min(minRight[i + 1], nums[i]);

    // Find the minimum sum
    for (int i = 1; i < n - 1; ++i) {
      if (nums[i] > minLeft[i - 1] && nums[i] > minRight[i + 1])
        ans = min(ans, nums[i] + minLeft[i - 1] + minRight[i + 1]);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};