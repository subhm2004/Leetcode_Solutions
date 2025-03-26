class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size(), n = grid[0].size();
    int total = m * n;  // Total elements ka count

    // Pehla element store kar lo, isse check karenge ki saare elements x ke multiple me change ho sakte hain ya nahi
    int base = grid[0][0];

    vector<int> nums;  // Saare elements ko store karne ke liye ek vector

    // Har element ko check karo
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((grid[i][j] - base) % x != 0)  
          return -1;  // Agar koi bhi element x ke multiple me convert nahi ho sakta toh return -1
        nums.push_back(grid[i][j]);  // Element ko list me store kar lo
      }
    }

    // Ab elements ko sort kar lo
    sort(nums.rbegin(), nums.rend());

    // Median nikal lo, kyunki minimum operations ke liye median best hota hai
    int median = nums[total / 2];

    int operations = 0;  // Minimum operations count karne ke liye variable

    // Har element ko median tak pahunchane ke liye required operations count karo
    for (int num : nums) {
      operations += abs(num - median) / x;  // Difference ko x ke multiples me convert karne ka count
    }

    return operations;  // Minimum operations return karo
  }
};
