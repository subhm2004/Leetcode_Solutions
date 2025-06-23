class Solution {
public:
    bool isPowerOfTwo(int n) { return n >= 0 && __builtin_popcount(n) == 1; }
};

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n == 1) {
//             return 1;
//         } else if (n % 2 == 0 && n != 0) {
//             return isPowerOfTwo(n / 2);
//         } else {
//             return 0;
//         }
//     }
// };
