class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int bitsA = __builtin_popcount(a); // Count 1s in binary representation of 'a'
      int bitsB = __builtin_popcount(b); // Count 1s in binary representation of 'b'
      return bitsA == bitsB ? a < b : bitsA < bitsB;
    });
    return arr;
  }
};
