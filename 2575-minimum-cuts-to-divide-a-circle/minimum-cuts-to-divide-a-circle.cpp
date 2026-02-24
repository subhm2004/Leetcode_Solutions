class Solution {
 public:
  int numberOfCuts(int n) {
    if (n == 1)
      return 0;
    return n % 2 == 0 ? n / 2 : n;
  }
};
// agar odd parts me divide krna hai to n cuts (n parts me divide kro if n = odd then required n cuts)
// agar even parts me divide krna hai to n/2 cuts (n parts me divide kro if n = even then required n/2 cuts)