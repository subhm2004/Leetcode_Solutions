// class Solution {
//  public:
//   vector<int> sortByBits(vector<int>& arr) {
//     sort(arr.begin(), arr.end(), [](int a, int b) {
//       int bitsA = __builtin_popcount(a); // Count 1s in binary representation of 'a'
//       int bitsB = __builtin_popcount(b); // Count 1s in binary representation of 'b'
//       return bitsA == bitsB ? a < b : bitsA < bitsB;
//     });
//     return arr;
//   }
// };

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    auto countBits = [](int n) {
      int count = 0;
      while (n) {
        count += (n & 1); // Check if the last bit is 1
        n >>= 1;          // Right shift to check the next bit
      }
      return count;
    };

    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int bitsA = countBits(a);
      int bitsB = countBits(b);
      return bitsA == bitsB ? a < b : bitsA < bitsB;
    });

    return arr;
  }
};

