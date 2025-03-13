class Solution {
 public:
  int returnToBoundaryCount(vector<int>& nums) {
    int sum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum == 0) count++;
    }
    return count;
  }
};
