class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    unordered_map<int, int> count1, count2;
    int n = nums.size();

    // Count occurrences of each number in nums
    for (int i = 0; i < n; ++i) 
      count2[nums[i]]++;

    for (int i = 0; i < n; ++i) {
      count1[nums[i]]++;  // Increase left part count
      count2[nums[i]]--;  // Decrease right part count
      
      if (count1[nums[i]] * 2 > i + 1 && count2[nums[i]] * 2 > n - i - 1)
        return i;
    }
    return -1;
  }
};
