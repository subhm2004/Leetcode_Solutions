// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int sum1 = (n * (n + 1)) / 2;
//         int sum2 = accumulate(nums.begin(), nums.end(), 0);
//         return sum1 - sum2;
//     }
// };


class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int xorAll = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      xorAll ^= i ^ nums[i];
    }

    xorAll ^= n;

    return xorAll;
  }
};