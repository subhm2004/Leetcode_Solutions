class Solution {
 public:
  int minInsertions(string s) {
    int neededRight = 0;  // Tracks how many ')' are needed
    int insertions = 0;   // Tracks how many insertions are needed

    for (const char c : s) {
      if (c == '(') {
        // If neededRight is odd, we have an extra ')', so we need 1 more ')'
        if (neededRight % 2 == 1) {
          ++insertions;   // Insert 1 ')'
          --neededRight;  // Adjust to match it
        }
        neededRight += 2;  // Every '(' needs two ')'
      } else {  // c == ')'
        --neededRight;  // Decrease neededRight as we match a ')'
        if (neededRight < 0) {
          ++insertions;   // Insert 1 '(' as there's no matching '('
          neededRight += 2;  // Now, this '(' needs two ')'
        }
      }
    }

    // If we have remaining ')' needed, we must insert them
    return insertions + neededRight;
  }
};
