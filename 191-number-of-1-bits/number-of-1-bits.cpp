class Solution {
 public:
 int count_Set_Bits_Fast(int n)
{
  int count = 0;
  while (n != 0)
  {
    // remove last set bit
    n = (n & (n - 1)); // last set bit hatao
    count++;
  }
  return count;
}
  int hammingWeight(int n) {
    // return __builtin_popcount(n);
    return count_Set_Bits_Fast(n);
  }
};


