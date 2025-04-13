class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    // int n = nums.size(), i = n - 2;

    // // Step 1: Find the first decreasing element from the right
    // while (i >= 0 && nums[i] >= nums[i + 1]) 
    //   i--;

    // // Step 2: If found, swap it with the next larger element from the right
    // if (i >= 0) {
    //   int j = n - 1;
    //   while (nums[j] <= nums[i]) 
    //     j--;
    //   swap(nums[i], nums[j]);
    // }

    // // Step 3: Reverse the remaining elements to get the next lexicographic order
    // reverse(nums.begin() + i + 1, nums.end());
    next_permutation(nums.begin(),nums.end());
  }
};
