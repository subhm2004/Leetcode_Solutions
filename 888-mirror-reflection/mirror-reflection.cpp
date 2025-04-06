class Solution {
 public:
  int mirrorReflection(int p, int q) {
    // dono even ho nhi skte
    while (p % 2 == 0 && q % 2 == 0) {
      p /= 2;
      q /= 2;
    }

    // Now decide based on the parity (even/odd) of p and q:

    // Case 1: If p is even => laser hits the left wall => receptor 2 (top-left)
    if (p % 2 == 0)
      return 2;

    // Case 2: If p is odd and q is even => laser hits the bottom wall => receptor 0 (bottom-right)
    if (q % 2 == 0)
      return 0;

    // Case 3: If both p and q are odd => laser hits the top wall => receptor 1 (top-right)
    return 1;
  }
};
