class Solution {
 public:
  int rand10() {
    int num = 40;  // Ensure the loop runs at least once
    while (num >= 40) {  // Reject numbers >= 40
      num = (rand7() - 1) * 7 + (rand7() - 1);  // Generate [0, 48]
    }
    return num % 10 + 1;  // Map [0, 39] → [1, 10]
  }
};
