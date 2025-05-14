class Solution {
 public:
  string triangleType(vector<int>& nums) {
    int a = nums[0], b = nums[1], c = nums[2];

    // Find the largest side
    int maxSide = max({a, b, c});
    int sumOfOthers = a + b + c - maxSide;

    // Triangle inequality: sum of two smaller > largest side
    if (sumOfOthers <= maxSide)
      return "none";

    // Check for type
    if (a == b && b == c)
      return "equilateral";
    if (a == b || b == c || a == c)
      return "isosceles";
    return "scalene";
  }
};
